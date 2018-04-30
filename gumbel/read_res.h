#ifndef READ_RES_H
#define READ_RES_H

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

int find_ss(float hs, float tp, float wd);
void get_sample(float hs, float tp, float wd, short i_var, double *spl);
void add_if_not_exist(float x, float *set, short *sz);
void analyse_results();
void read_results(const char *fname);
void show_results();
void show_sample();

#endif