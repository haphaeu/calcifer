/* from
https://www.geeksforgeeks.org/multithreading-c-2/

compile with:
    gcc pthreads.c -lpthread
*/
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>  //Header file for sleep(). man 3 sleep for details. 
#include <pthread.h>

#define MAX_NUM_THREADS 99
  
// A normal C function that is executed as a thread  
// when its name is specified in pthread_create() 
void *myThreadFun(void *vargp) 
{
    int sleep_sec = 1 + random() % 9;
    sleep(sleep_sec); 
    printf("Thread has slept for %d seconds.\n", sleep_sec); 
    return NULL; 
} 
   
int main(int argc, char *argv[]) 
{			   
    pthread_t thread_id[MAX_NUM_THREADS];
    int num_threads;	   
    if(argc == 1) {
	// default option
	num_threads = 3;
    } else {
	int n = atoi(argv[1]);
	num_threads = n < MAX_NUM_THREADS ? n : MAX_NUM_THREADS;
    }
    
    printf("Running %d thread%c.\n",
	   num_threads,
	   num_threads > 1 ? 's':' '
	   );
    
    for(int i=0; i<num_threads; ++i)
	pthread_create(&thread_id[i], NULL, myThreadFun, NULL);
    
    for(int i=0; i<num_threads; ++i)    
        pthread_join(thread_id[i], NULL);
    
    printf("After Thread\n"); 
    exit(0); 
}
