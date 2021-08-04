/*
Mock-up implementation using multithreading to benchmark performance.

This does do anything specific rather than calculating various
spectra and timetraces with very refined steps.

Linux:
    gcc jonswap_multithread.c -o jonswap_multithread -lm -lpthread -Wno-implicit-function-declaration

in windows, add the flags:
    -Dsrandom=srand -Drandom=rand -std=c11 


queue with pthread
https://stackoverflow.com/questions/4577961/pthread-synchronized-blocking-queue

#+AUTHOR Rafael Rossi
#+DATE 25-Oct-2019

*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include <pthread.h>
#include <time.h>

#define MAX_NUM_THREADS 99
#define XRES 1920
#define YRES 1080
#define XMAX 1.0
#define XMIN -2.0
#define YMAX 1.0
#define YMIN -1.0

double* XDOMAIN;
double* YDOMAIN;
int** ITERS;

int MAX_ITERS;

short verbose = 0;

void* worker_thread(void *vargp);
void mandel(int pixel_start, int pixel_end);


struct WorkerThreadArgs {
    int pixel_start;
    int pixel_end;
} thread_args[MAX_NUM_THREADS]; 


int main(int argc, char *argv[]) {
    
    pthread_t thread_id[MAX_NUM_THREADS];

    int num_threads;
    int pixel_per_thread;

    struct timespec start, finish;
    double elapsed;

    if(argc == 1) {
        // default option
        num_threads = 3;
        MAX_ITERS = 128;
    } else {
        // all options: max_iters num_threads
        MAX_ITERS = atoi(argv[1]);

        int n = atoi(argv[2]);
        num_threads = n < MAX_NUM_THREADS ? n : MAX_NUM_THREADS;
    }
    
    pixel_per_thread = XRES / num_threads + 1;

    // define a queue of args for the threads
    int c = 0;
    int end;
    for(int i=0; i<XRES; i+=pixel_per_thread) {
        end = i + pixel_per_thread;
        thread_args[c] = (struct WorkerThreadArgs) {
            .pixel_start = i,
            .pixel_end = end < XRES ? end : XRES
        };
        if (verbose)
            printf("%d\t%d\t%d\n", 
                c, 
                thread_args[c].pixel_start, 
                thread_args[c].pixel_end);
        c++;
    }
    
    // init domains
    XDOMAIN = (double*) malloc(XRES * sizeof(double));
    YDOMAIN = (double*) malloc(YRES * sizeof(double));
    ITERS = (int**) malloc(XRES * sizeof(int*));
    for (int i=0; i<XRES; i++)
        ITERS[i] = (int*) malloc(YRES * sizeof(int));
    
    // calculate domains
    double xdelta = (XMAX - XMIN) / XRES;
    double ydelta = (YMAX - YMIN) / YRES;
    
    for (int i=0; i < XRES; i++)
            XDOMAIN[i] = XMIN + i * xdelta;

    for (int i=0; i < YRES; i++)
        YDOMAIN[i] = YMIN + i * ydelta;


    ////////////////////////////////////////////////////////////////////////
    /////////// Running multi threaded /////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////
    printf("Running %d thread%c, %d max iters and %d pixels per thread.\n",
           num_threads, num_threads > 1 ? 's':' ', MAX_ITERS, pixel_per_thread);
    clock_gettime(CLOCK_MONOTONIC, &start);

    // create and launch all threads
    if (verbose) printf("Creating threads ");
    for(int i=0; i<num_threads; ++i) {
        if (verbose) printf("%d ", i);
        pthread_create(&thread_id[i], NULL, worker_thread, thread_args+i);
    }
    
    if (verbose) printf("\nJoining threads ");
        
    // wait until all threads are done
    for(int i=0; i<num_threads; ++i) {
        if (verbose) printf("%d ", i);
        pthread_join(thread_id[i], NULL);
    }
        
    if (verbose) printf("\n");

    clock_gettime(CLOCK_MONOTONIC, &finish);
    elapsed = (finish.tv_sec - start.tv_sec);
    elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;
    printf("Done with all threads - %.3fs\n", elapsed);

    exit(0); 

}


void* worker_thread(void *vargp) {

    struct WorkerThreadArgs* args = (struct WorkerThreadArgs *) vargp; 

    int pixel_start = args->pixel_start;
    int pixel_end = args->pixel_end;
    
    if (verbose) printf("  Hi from thread pixel_start %d\n", pixel_start);
    
    mandel(pixel_start, pixel_end);

    return NULL;
}

void mandel(int pixel_start, int pixel_end) {
    
    int c;
    double x0, y0, x1, y1, xtmp;
        
    for (int i=pixel_start; i < pixel_end; i++) {
        x0 = XDOMAIN[i];
        for (int j=0; j < YRES; j++) {
            y0 = YDOMAIN[j];
            x1 = 0.0;
            y1 = 0.0;
            c = 0;
            while (x1*x1 + y1*y1 <= 4 && c < MAX_ITERS) {
                xtmp = x1*x1 - y1*y1 + x0;
                y1 = 2*x1*y1 + y0;
                x1 = xtmp;
                c++;
            }
            ITERS[i][j] = c;
        }
    }
}
