 /*

Gumbel a results.txt file.

@author Haphaeu

*/

#include <float.h>
#include "gumbel.h"
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
    double mu = xm - beta * 0.5772; // Euler�Mascheroni constant
    mu_beta[0] = mu;
    mu_beta[1] = beta;
 }
void gumbel_fit_min(double *v, int n, double* mu_beta) {
    // Gumbel using moments estimators
    double xm = mean(v, n);
    double sd = std_(v, n, xm);
    double beta = sd * 0.77969680;  // 6/sqrt(pi)
    double mu = xm + beta * 0.5772; // Euler�Mascheroni constant
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

/**********************************************************************/
/*********************************************************************/
/********************************************************************/

void summarise(const char *fname) {
    if (DBG) printf("in summarise()\n");
    
    if (DBG) printf("  calling read_results()\n");
    read_results(fname);
    
    if (DBG) printf("  calling analyse()\n");
    analyse_results();
    
    double sample[nseeds], p90, g90, tmp, mu_beta[2]={0.0, 0.0};
    short isMax;
    
    printf("\n\n");
    printf("%3s   %2s", "Hs", "Tp");
    for (int i=0; i<nvars; i++)
        printf("%20s", vars_names[i]);
    printf("\n        ");
    for (int i=0; i<nvars; i++)
        printf("%10s%10s", "g90", "p90");
    printf("\n");
    for (int i=0; i<nhs; i++) {
        for (int j=0; j<ntp[i]; j++) {
            printf("%.1f   %2.0f", hs[i], tp[i][j]);
            for (int k=0; k<nvars; k++) {
                if(strstr(vars_names_lower[k], "max")) {
                    isMax = 1;
                    p90 = g90 = -DBL_MAX;
                } else /* minima */ {
                    isMax = 0;
                    p90 = g90 = DBL_MAX;
                } 
                for (int l=0; l<nwd; l++) {
                    get_sample(hs[i], tp[i][j], wd[l], k, sample);
                    if (isMax) { 
                        gumbel_fit_max(sample, nseeds, mu_beta);
                        tmp = gumbel_ppf_max(mu_beta[0], mu_beta[1], 0.9);
                        g90 = max(g90, tmp);  // do not use function call here, see definition above
                        tmp = quantile(sample, nseeds, 0.9);
                        p90 = max(p90, tmp);  // do not use function call here, see definition above
                    } else {
                        gumbel_fit_min(sample, nseeds, mu_beta);
                        tmp = gumbel_ppf_min(mu_beta[0], mu_beta[1], 0.9);
                        g90 = min(g90, tmp);  // do not use function call here, see definition above
                        tmp = quantile(sample, nseeds, 1-0.9);
                        p90 = min(p90, tmp);  // do not use function call here, see definition above
                    } 
                } 
                printf("%10.3f%10.3f", g90, p90); 
            }
            printf("\n");
        }
    }
}

void print_sample() {
    double sample[nseeds];
    get_sample(3.5, 14, 195, 0, sample);
    for (int i=0; i<nseeds; i++) printf("%.6f\n", sample[i]);
}


int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Using %s\n", "results.txt");
        summarise("results.txt");
    } else {
        printf("Using %s\n", argv[1]);
        summarise(argv[1]);
    }
    return 0;
}
