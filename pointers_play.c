/*
Benchmark array vs pointer operations

Pointers showed up to be 10% faster.

#define SIZE 100000
array 43s 631ms
pointer 39s 672ms


*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define SIZE 100000

void do_array(double v[]) {
    // stupid sort algorithm
    // implemented with array operations []
    short flag = 1;
    int i;
    double tmp;
    while (flag) {
        flag = 0;
        for (i = 0; i < SIZE - 1; i++)
            if (v[i] > v[i+1]) {
		tmp = v[i];
		v[i] = v[i+1];
		v[i+1] = tmp;
                flag = 1;
            }
    }
}

void do_pointer(double *v) {
    // stupid sort algorithm
    // implemented with pointers operations *
    short flag = 1;
    int i;
    double tmp, *vo = v;
    while (flag) {
        flag = 0;
        for (i = 0, v = vo; i < SIZE - 1; i++, v++)
            if ( *v > *(v+1) ) {
		tmp = *v;
		*v = *(v+1);;
		*(v+1) = tmp;
                flag = 1;
            }
    }
}

int main(int argc, char **argv) {
    clock_t t0;
    int msec;
    double v[SIZE];
    double v2[SIZE];
    for (int i=0; i<SIZE; i++) {
        v[i] = (double) rand()/RAND_MAX;
	v2[i] = v[i];
    }
    
    for (int i=0; i < 8; i++) printf("%.3f ", v2[i]); printf("...");
    for (int i=SIZE-8; i < SIZE; i++) printf("%.3f ", v2[i]); printf("\n");
    
    t0 = clock();    do_array(v2);    t0 = clock() - t0;
    for (int i=0; i < 8; i++) printf("%.3f ", v2[i]); printf("...");
    for (int i=SIZE-8; i < SIZE; i++) printf("%.3f ", v2[i]); printf("\n");
    msec = t0 * 1000 / CLOCKS_PER_SEC;
    printf("array %ds %dms\n", msec/1000, msec%1000);
    
    // restore v2
    for (int i=0; i<SIZE; i++)  v2[i] = v[i];

    for (int i=0; i < 8; i++) printf("%.3f ", v2[i]); printf("...");
    for (int i=SIZE-8; i < SIZE; i++) printf("%.3f ", v2[i]); printf("\n");

    t0 = clock();    do_pointer(v2);    t0 = clock() - t0;
    for (int i=0; i < 8; i++) printf("%.3f ", v2[i]); printf("...");
    for (int i=SIZE-8; i < SIZE; i++) printf("%.3f ", v2[i]); printf("\n");
    msec = t0 * 1000 / CLOCKS_PER_SEC;
    printf("pointer %ds %dms\n", msec/1000, msec%1000);

    return 0;
}




