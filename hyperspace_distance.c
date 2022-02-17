/*

Calculate closest and furthest neighbor in high dimensional space.

The neighbors tend to cluster in the shell in higher spaces.

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

#define minN 10000
#define maxN 11000
#define stepN 2000
#define M 10000
#define DBG 0

double* dist_Euclidian(double *ref, double *sample, int n) {
    static double dist[M];
    double sum;
    for (int j=0; j<M; j++) {
        sum = 0.0;
        for (int i=0; i<n; i++) {
            sum += pow(ref[i] - sample[j*M+i], 2);
        }
        dist[j] = pow(sum, 0.5);
    }
    return dist;
}

double* generate(const int n) {
    static double vect[M*maxN];
    for (int j=0; j<M; j++) {
        for (int i=0; i<n;i++) {
            vect[j*M+i] = (double)rand()/RAND_MAX;
        }
    }
    return vect;
}


double* generate_ref(const int n) {
    static double vect[maxN];
    for (int i=0; i<n;i++) {
        vect[i] = (double)rand()/RAND_MAX;
    }
    return vect;
}

double* get_stats(double *dist) {
    double ave, mn, mx;
    static double stats[3];

    ave = 0.0;
    mn = DBL_MAX; mx = -DBL_MAX;
    for (int j=0; j<M; j++) {
        ave += dist[j];
        if (dist[j] < mn)
            mn = dist[j];
        if (dist[j] > mx)
            mx = dist[j];
    }
    ave /= M;
    stats[0] = ave; stats[1] = mn; stats[2] = mx;
    return stats;
}

int do_stuff() {
    
    double* stats;
    double* ref;
    double* sample;
    double *dist;
    
    clock_t tc;
    int msec;

    for (int n=minN; n<maxN; n+=stepN) {
        
        tc = clock();
        ref = generate_ref(n);
        msec = (clock() - tc) * 1000 / CLOCKS_PER_SEC;
        printf("generate_ref \t %ds %dmsec\n", msec/1000, msec%1000);
        
        tc = clock();
        sample = generate(n);
        msec = (clock() - tc) * 1000 / CLOCKS_PER_SEC;
        printf("generate     \t %ds %dmsec\n", msec/1000, msec%1000);
        
        tc = clock();
        dist = dist_Euclidian(ref, sample, n);
        msec = (clock() - tc) * 1000 / CLOCKS_PER_SEC;
        printf("dist_Eucl.   \t %ds %dmsec\n", msec/1000, msec%1000);
        
        tc = clock();
        stats = get_stats(dist);
        msec = (clock() - tc) * 1000 / CLOCKS_PER_SEC;
        printf("get_stats    \t %ds %dmsec\n", msec/1000, msec%1000);
        
        tc = clock();
        free(ref);
        free(sample);
        msec = (clock() - tc) * 1000 / CLOCKS_PER_SEC;
        printf("free took    \t %ds %dmsec\n", msec/1000, msec%1000);
        
        printf("%d \t %.2f \t %.2f \t %.2f \n", n, stats[0], stats[1], stats[2]);
    }
    
    return 0;
}

int main() {
    clock_t t0 = clock();
    do_stuff();
    t0 = clock() - t0;
    int msec = t0 * 1000 / CLOCKS_PER_SEC;
    printf("============\nruntime %ds %dms\n", msec/1000, msec%1000);
}

