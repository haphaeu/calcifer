
#ifndef GUMBEL_H
#define GUMBEL_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

#include "sort.h"

// do not use function call here otherwise it will be called twice
#define max(X, Y) (((X) > (Y)) ? (X) : (Y))
#define min(X, Y) (((X) < (Y)) ? (X) : (Y))

#define DBG 0

double sum(double *v, int n);
double mean(double *v, int n);
double std_(double *v, int n, double xm);
double std(double *v, int n);
void gumbel_fit_max(double *v, int n, double* mu_beta);
void gumbel_fit_min(double *v, int n, double* mu_beta);
double gumbel_ppf_max(double mu, double beta, float p);
double gumbel_ppf_min(double mu, double beta, float p);
double quantile(double *v, int n, float p);

#endif