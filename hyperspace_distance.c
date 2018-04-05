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
#include <time.h>

#define minN 1000
#define maxN 10000
#define stepN 500
#define M 10000
#define DBG 0

double* dist_Euclidian(double *ref, double *sample, int n) {
    if (DBG) printf("  Calling dist \n");
    if (DBG) printf("    declaration \n");
    static double dist[M];
    double sum;
    if (DBG) printf("    starting for loop \n");
    for (int j=0; j<M; j++) {
      if (DBG) printf("      j=%d \n", j);
      sum = 0.0;
      for (int i=0; i<n; i++) {
        if (DBG) printf("        i=%d \n", i);
        if (DBG) printf("        ref[%d]=%.2f\n", i, ref[i]);
        if (DBG) printf("        sample[%d][%d]=%.2f\n", j, i, sample[j*M+i]);
        sum += pow(ref[i] - sample[j*M+i], 2);
      }
      dist[j] = pow(sum, 0.5);
    }
    return dist;
}

double* generate(const int n) {
    if (DBG) printf("  Inside generate \n");
    static double vect[M*maxN];
    for (int j=0; j<M; j++) {
      for (int i=0; i<n;i++) {
        vect[j*M+i] = (double)rand()/RAND_MAX;
        if (DBG) printf("  vect[%d][%d] = %.2f \n", j, i, vect[j*M+i]);
      }
    }
    return vect;
}


double* generate_ref(const int n) {
    if (DBG) printf("  Inside generate_ref \n");
    static double vect[maxN];
    for (int i=0; i<n;i++) {
        vect[i] = (double)rand()/RAND_MAX;
        if (DBG) printf("  vect[%d] = %.2f \n", i, vect[i]);
    }
    return vect;
}

double* get_stats(double *dist) {
  if (DBG) printf("  inside get_stats \n");
  double ave, mn, mx;
  static double stats[3];

  ave = 0.0;
  mn = 999.999; mx = -999.999;
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

    for (int n=minN; n<maxN; n+=stepN) {
      if (DBG) printf("Start n = %d\n", n);
      if (DBG) printf("Calling generate ref \n");
      ref = generate_ref(n);
      if (DBG) {
        printf("This is ref: \t");
        for (int i=0; i<n;i++) {
          printf("%.2f \t", ref[i]);
        }
        printf(" \n");
        printf("Calling generate sample \n");
      }
      sample = generate(n);
      if (DBG) printf("This is sample: \t");
      for (int j=0; j<M; j++)
        for (int i=0; i<n;i++)
          if (DBG) printf("%.2f \t", sample[j*M+i]);
      if (DBG) printf("Calling get_stats \n");
      stats = get_stats(dist_Euclidian(ref, sample, n));
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
