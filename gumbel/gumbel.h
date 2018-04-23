 /*

Gumbel a results.txt file.

@author Haphaeu

*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>


#include "sort.h"
#include "read_res.h"

double sum(double *v, int n) {
    double x = 0.0;
    for (int i=0; i<n; i++)
        x += v[i];
    return x;
}
double mean(double *v, int n) {
    return sum(v, n)/n;
}
double std_(double *v, int n, double xm) {
    double xs = 0.0;
    for (int i=0; i<n; i++)
        xs += pow(v[i] - xm, 2);
    // std in numpy and scipy use (n)
    // excel stdev uses (n-1) and stdevp uses (n)
    // pandas uses (n-1)
    return sqrt(xs/(n-1)); 
}
double std(double *v, int n) {
    double xm = mean(v, n);
    return std_(v, n, xm);
}
void gumbel_fit_max(double *v, int n, double* mu_beta) {
    // Gumbel using moments estimators
    double xm = mean(v, n);
    double sd = std_(v, n, xm);
    double beta = sd * 0.77969680;  // 6/sqrt(pi)
    double mu = xm - beta * 0.5772; // Euler–Mascheroni constant
    mu_beta[0] = mu;
    mu_beta[1] = beta;
 }
void gumbel_fit_min(double *v, int n, double* mu_beta) {
    // Gumbel using moments estimators
    double xm = mean(v, n);
    double sd = std_(v, n, xm);
    double beta = sd * 0.77969680;  // 6/sqrt(pi)
    double mu = xm + beta * 0.5772; // Euler–Mascheroni constant
    mu_beta[0] = mu;
    mu_beta[1] = beta;
 }
double gumbel_ppf_max(double mu, double beta, float p) {
    // Gumbel maximum 
    return mu - beta * log(-log(p));  // max
}
double gumbel_ppf_min(double mu, double beta, float p) {
    // Gumbel minimum 
    return mu + beta * log(-log(p));  // min
}

double quantile(double *v, int n, float p) {
    /* Quantile p (percentile 100*p) of the data in v of length n.
     * Performs liner interpolation if quantile is between two data points.
     */
    sort(v, n);  // if v already sorted, this should have very low cost
    float qi = p*(n-1);
    int i = (int) qi;
    return (qi-i) * (v[i+1]-v[i]) + v[i];
}

