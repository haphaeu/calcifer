/*

Calculate closest and furthest neighbor in high dimensional space.

The neighbors tend to cluster in the shell in higher spaces.

This is a modified version of the code using dynamic allocation instead of static.
See if I still remember how to use mallocs...

@author Haphaeu

code in python:

import numpy as np

def dist_Euclidian(ref, sample):
    return (((sample-ref)**2).sum(axis=1))**0.5

def dist_Manhatan(ref, sample):
    return ((abs(sample-ref)).sum(axis=1))

def test(n, m, dist=dist_Euclidian, distr=np.random.normal):
    ref = distr(size=(1, n))
    sample = distr(size=(m, n))
    d = dist(ref, sample)
    return d.mean(), d.std(), d.min(), d.max()

def do_stuff():
    print(' n \t mean \t std \t min \t max')
    for i in range(1000, 10000, 500):
        print('%2d \t %.2f \t %.2f \t %.2f \t %.2f' % (i, *test(i, 10000)))

*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <time.h>

//#define DBG 1
int DBG;

double* dist_Euclidian(double *ref, double *sample, long n, int m) {

    double *distE;
    distE = (double*) malloc(m * sizeof(double));
    
    double sum;
    for (int j=0; j<m; j++) {
        sum = 0.0;
        for (long i=0; i<n; i++) {
            sum += pow(ref[i] - sample[j*n+i], 2);
        }
        distE[j] = pow(sum, 0.5);
    }
    return distE;
}

double* generate(const long n, const int m) {
    static double *vect;
    printf("generating n, m, n*m: %d, %d, %d\n", n, m, m*n);
    vect = (double*) malloc(m*n * sizeof(double));
    
    for (int j = 0; j < m; j++) {
        for (long i = 0; i < n; i++) {
            vect[j*n + i] = (double) rand()/RAND_MAX;
        }
    }
    return vect;
}

double* get_stats(double *dist, const int m) {
    double ave, mn, mx;
    static double stats[3];

    ave = 0.0;
    mn = DBL_MAX; mx = -DBL_MAX;
    for (int j=0; j<m; j++) {
        ave += dist[j];
        if (dist[j] < mn)
            mn = dist[j];
        if (dist[j] > mx)
            mx = dist[j];
    }
    ave /= m;
    stats[0] = ave; stats[1] = mn; stats[2] = mx;
    return stats;
}

int do_stuff(long minN, long maxN, int stepN, int m) {
    
    double* stats;
    double* ref;
    double* sample;
    double* dist;
    
    clock_t tc;
    int msec;

    for (long n=minN; n<maxN; n+=stepN) {
        
        tc = clock();
        ref = generate(n, 1);
        msec = (clock() - tc) * 1000 / CLOCKS_PER_SEC;
        if (DBG) printf("generate_ref \t %ds %dmsec\n", msec/1000, msec%1000);
        
        tc = clock();
        sample = generate(n, m);
        msec = (clock() - tc) * 1000 / CLOCKS_PER_SEC;
        if (DBG) printf("generate     \t %ds %dmsec\n", msec/1000, msec%1000);
        
        tc = clock();
        dist = dist_Euclidian(ref, sample, n, m);
        msec = (clock() - tc) * 1000 / CLOCKS_PER_SEC;
        if (DBG) printf("dist_Eucl.   \t %ds %dmsec\n", msec/1000, msec%1000);
        
        tc = clock();
        stats = get_stats(dist, m);
        msec = (clock() - tc) * 1000 / CLOCKS_PER_SEC;
        if (DBG) printf("get_stats    \t %ds %dmsec\n", msec/1000, msec%1000);
        
        tc = clock();
        free(ref);
        free(sample);
        msec = (clock() - tc) * 1000 / CLOCKS_PER_SEC;
        if (DBG) printf("free took    \t %ds %dmsec\n", msec/1000, msec%1000);
        
        printf("%d \t %.2f \t %.2f \t %.2f \n", n, stats[0], stats[1], stats[2]);
    }
    
    return 0;
}

int main(int argc, char *argv[]) {
    if ( argc < 5 ) 
    {
        printf( "usage: %s minN maxN stepN M", argv[0] );
        return 1;
    }
    DBG = 0;
    if ( argc == 6)
        DBG = atoi(argv[5]);
    
    unsigned long minN = atoi(argv[1]);
    unsigned long maxN = atoi(argv[2]);
    unsigned int stepN = atoi(argv[3]);
    unsigned int m = atoi(argv[4]);
    
    
    clock_t t0 = clock();
    do_stuff(minN, maxN, stepN, m);
    t0 = clock() - t0;
    int msec = t0 * 1000 / CLOCKS_PER_SEC;
    printf("============\nruntime %ds %dms\n", msec/1000, msec%1000);
    
    return 0;
}

