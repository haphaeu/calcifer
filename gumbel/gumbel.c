
#include <float.h>
#include "gumbel.h"

// do not use function call here otherwise it will be called twice
#define max(X, Y) (((X) > (Y)) ? (X) : (Y))
#define min(X, Y) (((X) < (Y)) ? (X) : (Y))

#define DBG 0

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

