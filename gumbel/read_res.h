/*

Read results.txt from lifting analysis batch.


matrix 
======
Array that contains all the results in a 1-dimensional array.
 
Results have the format:
    Hs  Tp  Wd  v1  v2  v3
    x   x   x   x   x   x
    x   x   x   x   x   x
 
Number of columns = 3 + number of variables
Number of rows = number of seeds * number of seastates (Hs, Tp) * number of directions
Rows are sorted first by Hs, then by Tp, and finally by Wd.

Results are found by the help function find_ss() and get_sample()

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define LINE_SIZE 300        // max line length in results.txt
#define MAX_VARS 50          // max number of variables in results.txt
#define MAX_VARNAME_SIZE 50  // max length of variable name
#define MAX_SEEDS 200        // max number of seeds


#define MAX_NUM_HS 30  
#define MAX_NUM_TP 12  
#define NUM_WD 3       
#define MATRIX_SZ MAX_SEEDS*(MAX_VARS+3)*MAX_NUM_HS*MAX_NUM_TP*NUM_WD

#define DBG 0

static double matrix[MATRIX_SZ];
char vars_names[MAX_VARS][MAX_VARNAME_SIZE];
char vars_names_lower[MAX_VARS][MAX_VARNAME_SIZE];
float hs[MAX_NUM_HS];
float wd[NUM_WD];
float tp[MAX_NUM_HS][MAX_NUM_TP];
short nhs;
short nwd;
short ntp[MAX_NUM_HS];
short ncols, nrows;
short nvars;
short nseeds;


int find_ss(float hs, float tp, float wd) {
    float hsi, tpi, wdi;
    int row;
    for (row=0; ; row++) {
        hsi = matrix[row*(3+nvars) + 0];
        tpi = matrix[row*(3+nvars) + 1];
        wdi = matrix[row*(3+nvars) + 2];
        if ( (fabs(hs-hsi) < 1e-4) && (fabs(tp-tpi) < 1e-4) && (fabs(wd-wdi) < 1e-4) ) {
            return row;
        }
    }
}


void get_sample(float hs, float tp, float wd, short i_var, double *spl) {
    //double *spl;
    //spl = (double*) malloc(nseeds * sizeof(double));
    int i0 = find_ss(hs, tp, wd);
    for (int i=0; i<nseeds; i++)
        spl[i] = matrix[(i0+i)*(3+nvars) + 3 + i_var];
    //return spl;
}

void add_if_not_exist(float x, float *set, short *sz) {
    /* Adds x to set if x not in set.
    sz is the current size of set
    */
    for (short i=0; i<*sz; i++) {
        if (fabs(x-set[i]) < 1e-4)
            return;
    }
    set[(*sz)++] = x; // operator ++ precedes *, hence the parenthesis
}

void analyse_results() {
    if (DBG) printf("in analyse_results()\n");
    
    float hsi, tpi, wdi, hsi0, tpi0, wdi0;
    short nseedsi = 0, nseeds0 = 0;
    long i;
    nhs = 0; nwd = 0; 
    for (i=0; i<MAX_NUM_HS; i++)
        ntp[i] = 0;
    for (i=0; i < nrows; i++) {
        hsi = matrix[i*(3+nvars) + 0];
        tpi = matrix[i*(3+nvars) + 1];
        wdi = matrix[i*(3+nvars) + 2];
        nseedsi++; // increment number of seed
        
        // NEED TO ADD A CHECK OF LIMITS HERE
        add_if_not_exist(hsi, hs, &nhs);
        add_if_not_exist(tpi, tp[nhs-1], &ntp[nhs-1]);
        add_if_not_exist(wdi, wd, &nwd); 
        if (DBG) printf("nhs, ntp[hs], nwd: %d, %d, %d\n", nhs, ntp[nhs-1], nwd);
        
        // This long if below is to capture the number of seeds
        // and make sure that all sea states have the same nseeds
        if (i>0) {
            if ( (fabs(hsi-hsi0) > 1e-4) || 
                 (fabs(tpi-tpi0) > 1e-4) ||
                 (fabs(wdi-wdi0) > 1e-4) ) {
                nseedsi--;
                
                if (0*DBG) printf("  row, seed, Hs, Tp, Wd: %d, %d, %.1f, %.1f, %.0f\n", i, nseedsi, hsi, tpi, wdi);
                
                if (nseeds0 && (nseeds0 != nseedsi))
                    printf("\n\nERRO - number of seeds varied - cases crahed?");
                nseeds0 = nseedsi;
                nseedsi = 1;
            }
        }
        hsi0 = hsi;
        tpi0 = tpi;
        wdi0 = wdi; 
    }
    
    nseeds = nseedsi;
    printf("Got %d seeds\n", nseedsi);
    printf("Got %d WD:", nwd);
    for (i=0; i<nwd; i++)
        printf("  %.1f", wd[i]);
        
    printf("\nGot %d Hs:", nhs);
    for (i=0; i<nhs; i++)
        printf("  %.1f", hs[i]);
    
    printf("\nGot Tp per Hs:");
    for (i=0; i<nhs; i++) {
        printf("\n  Hs %.1f got %d Tps:", hs[i], ntp[i]);
        for (int j=0; j<ntp[i]; j++)
            printf("  %.1f", tp[i][j]);
    }
    printf("\n");
    
    if (DBG) printf("end analyse_results\n");
}

void read_results(const char *fname) {
    if (DBG) printf("in read_results()\n");
    
    char line[LINE_SIZE];
    char *token;
    FILE * fp;
    
    fp = fopen (fname, "r");
    
    // Reads the head line
    nvars = -3; 
    fgets(line, LINE_SIZE, fp);
    line[strcspn(line, "\r\n")] = 0;
    token = strtok(line, "\t");
    while( token != NULL ) {
        if (0) printf( "%s\t", token);
        if (++nvars > 0) 
            strcpy(vars_names[nvars-1], token);
        token = strtok(NULL, "\t");
    }
    ncols = nvars+3;
    
    // Creates a lower-case copy of the variable names
    for (int i=0; i<nvars; i++) {
        strcpy(vars_names_lower[i], vars_names[i]);
        char *p = vars_names_lower[i];
        for ( ; *p; ++p) *p = tolower(*p);  // converts vars_names_lower to lower case
        if (DBG) printf("%s  ->  %s\n", vars_names[i], vars_names_lower[i]);

    }

    // Continue reading the values
    short ihs, itp, iwd, ivar, iseed;
    int i = 0, rows=0;
    float wdi;

    while(fgets(line, LINE_SIZE, fp)) {
        line[strcspn(line, "\r\n")] = 0;
        token = strtok(line, "\t");
        while( token != NULL ) {
            matrix[i++] = atof(token);
            if (0) printf("%s\t", token );
            token = strtok(NULL, "\t");
        }
        rows++;
    }
    nrows = rows;
    fclose(fp);
    
    if (DBG) printf("end read_results()\n");
}


void show_results() {
    printf("\n\nPrinting results from arrays\n\n");

    printf("Hs\tTp\twd");
    for (int i=0; i<nvars; i++) printf("\t%s", vars_names[i]);
    for (int i=0; i<nrows; i++) {
        if (!(i%ncols)) printf("\n"); else printf("\t");
        printf("%.6f", matrix[i]);
    }
}


void show_sample() {
    printf("\n\nTesting get_sample\n\n");
    double sample[nseeds];
    get_sample(3.5, 14.0, 195.0, 0, sample);
    for (int i=0; i<nseeds; i++)
        printf("%f\n", sample[i]);
}



