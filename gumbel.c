/*

Gumbel a results.txt file.

@author Haphaeu

*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <time.h>

#define swap(i, j, type) {type t = i; i = j; j = t;}


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
    return sqrt(xs/(n)); // numpy and scipy use (n), excel stdev uses (n-1), stdevp uses (n)
}
double std(double *v, int n) {
    double xm = mean(v, n);
    return std_(v, n, xm);
}
double *gumbel(double *v, int n) {
    static double mu_beta[2];
    double xm = mean(v, n);
    double sd = std_(v, n, xm);
    double beta = sd * 0.77969680;  // 6/sqrt(pi)
    double mu = xm - beta * 0.5772; // Euler–Mascheroni constant
    mu_beta[0] = mu;
    mu_beta[1] = beta;
    return mu_beta;
 }
double gumbel_max(double mu, double beta, float p) {
    // Gumbel maximum using moments estimators
    return mu - beta * log(-log(p));  // max
}
double gumbel_min(double mu, double beta, float p) {
    // Gumbel minimum using moments estimators
    return mu + beta * log(-log(1-p));  // min
}
void sort(double *v, int n) {
    // very simple sort ascending algorithm
    // lots of rrom for improvement speed here
    short flag = 1;
    while (flag) {
        flag = 0;
        for (int i=0; i<n-1; i++)
            if (v[i] > v[i+1]) {
                swap(v[i], v[i+1], double);
                flag = 1;
            }
    }
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

/**********************************************************/
void test_sort_performance() {

    clock_t t0;
    int msec;
    double *v;
    long n = 7500;
    v = (double *) malloc(n * sizeof(double));

    for (int i=0; i<n; i++)
        v[i] = (double) rand()/RAND_MAX;

    t0 = clock(); sort(v, n); t0 = clock() - t0;
    msec = t0 * 1000 / CLOCKS_PER_SEC;
    printf("sort unsorted %ds %dms\n", msec/1000, msec%1000);
    
    t0 = clock(); sort(v, n); t0 = clock() - t0;
    msec = t0 * 1000 / CLOCKS_PER_SEC;
    printf("sort sorted %ds %dms\n", msec/1000, msec%1000);
}
/************************************************************/

int main(int argc, char *argv[]) {
    double mu, beta, *ret;
    double x[10] = {8, 2, 6, 1, 10, 9, 3, 4, 7, 5};
    ret = gumbel(x, 10);
    mu = ret[0];
    beta = ret[1];
    
    printf("orig   x:");
    for (int i=0; i<10; i++) printf(" %.1f", x[i]);
    printf("\n");
    sort(x, 10);
    printf("sorted x:");
    for (int i=0; i<10; i++) printf(" %.1f", x[i]);
    printf("\n");
        
    printf("sum %f\n", sum(x, 10));
    printf("mean %f\n", mean(x, 10));
    printf("std %f\n", std(x, 10));
    printf("std %f\n", std_(x, 10, mean(x, 10)));
    printf("gmax %f\n", gumbel_max(mu, beta, 0.9));
    printf("gmin %f\n", gumbel_min(mu, beta, 0.9));
    printf("p90 %f\n", quantile(x, 10, 0.9));
    printf("p10 %f\n", quantile(x, 10, 0.1));
    
    test_sort_performance();
    
    return 0;
}

