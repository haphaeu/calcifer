#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_SIZE 200
#define MAX_VARS 50
#define MAX_VARNAME_SIZE 50
#define MAX_SEEDS 200
#define MAX_NUM_HS 25
#define MAX_NUM_TP 12
#define NUM_WD 3

void read_results(short nseeds) {
    char line[LINE_SIZE];
    char *token;
    
    short nvars = -3; 
    short ncols, nrows;
    char vars_names[MAX_VARS][50];
    
    float matrix[450000];
    
    FILE * fp;
    
    fp = fopen ("results_mini.txt", "r");
    
    // Reads the head line
    fgets(line, LINE_SIZE, fp);
    line[strcspn(line, "\r\n")] = 0;
    token = strtok(line, "\t");
    while( token != NULL ) {
        printf( "%s\t", token);
        if (++nvars > 0) 
            strcpy(vars_names[nvars-1], token);
        token = strtok(NULL, "\t");
    }
    ncols = nvars+3;
    
    // Continue reading the values
    short ihs, itp, iwd, ivar, iseed, i = 0;
    float wdi;
    
    while(fgets(line, LINE_SIZE, fp)) {
        line[strcspn(line, "\r\n")] = 0;
        token = strtok(line, "\t");
        while( token != NULL ) {
            matrix[i++] = atof(token);
            printf("%s\t", token );
            
            token = strtok(NULL, "\t");
        }
    }
    nrows = i;
    fclose(fp);
    
    printf("Hs\tTp\twd");
    for (int i=0; i<nvars; i++) printf("\t%s", vars_names[i]);
    for (int i=0; i<nrows; i++) {
        if (!(i%ncols)) printf("\n"); else printf("\t");
        printf("%.6f", matrix[i]);
    }
    
}
int main() {
    read_results(3);
    return 0;
}
