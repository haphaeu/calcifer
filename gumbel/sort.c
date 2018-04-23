#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "sort.h"


/* Function to print an array */
void printArray(double arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%.1f ", arr[i]);
    printf("\n");
}


void test_sort_performance() {
    /*
    Test performance of the sort() function for
    already sorted arrays and compares against randomly 
    unsorted arrays.
    
    This is because sort() is being called without any
    check if array is already sorted.
    
    If cost of trying to sort an already sorted array is low 
    enough, there is not reason to check for sorted...
    
    */
    short print = 0;
    
    clock_t t0;
    int msec;
    double *v;
    long n = 5000000;
    
    /***************************************************************************
       First using stupid_sort()
    ****************************************************************************
    v = (double *) malloc(n * sizeof(double));

    for (int i=0; i<n; i++)
        v[i] = (double) rand()/RAND_MAX;

    if (print) printArray(v, n);
    t0 = clock(); stupid_sort(v, n); t0 = clock() - t0;
    msec = t0 * 1000 / CLOCKS_PER_SEC;
    printf("sort unsorted %ds %dms\n", msec/1000, msec%1000);
    
    if (print) printArray(v, n);
    t0 = clock(); stupid_sort(v, n); t0 = clock() - t0;
    msec = t0 * 1000 / CLOCKS_PER_SEC;
    printf("sort sorted %ds %dms\n", msec/1000, msec%1000);
    
    free(v);
    
    /***************************************************************************
       Then using quick_sort()
    ****************************************************************************
    
    v = (double *) malloc(n * sizeof(double));

    for (int i=0; i<n; i++)
        v[i] = (double) rand()/RAND_MAX;

    if (print) printArray(v, n);
    t0 = clock(); quick_sort(v, 0, n-1); t0 = clock() - t0;
    msec = t0 * 1000 / CLOCKS_PER_SEC;
    printf("sort unsorted %ds %dms\n", msec/1000, msec%1000);
    
    if (print) printArray(v, n);
    t0 = clock(); quick_sort(v, 0, n-1); t0 = clock() - t0;
    msec = t0 * 1000 / CLOCKS_PER_SEC;
    printf("sort sorted %ds %dms\n", msec/1000, msec%1000);
    
    free(v);
    
    /***************************************************************************
       And finally using if(is_sorted()) quick_sort()
    ****************************************************************************/
    
    v = (double *) malloc(n * sizeof(double));

    for (int i=0; i<n; i++)
        v[i] = (double) rand()/RAND_MAX;

    if (print) printArray(v, n);
    t0 = clock(); if ( ! is_sorted(v, n)) quick_sort(v, 0, n-1); t0 = clock() - t0;
    msec = t0 * 1000 / CLOCKS_PER_SEC;
    printf("sort unsorted %ds %dms\n", msec/1000, msec%1000);
    
    if (print) printArray(v, n);
    t0 = clock(); if ( ! is_sorted(v, n)) quick_sort(v, 0, n-1); t0 = clock() - t0;
    msec = t0 * 1000 / CLOCKS_PER_SEC;
    printf("sort sorted %ds %dms\n", msec/1000, msec%1000);
}



// Driver program to test above functions
int main()
{
    test_sort_performance();
    return 0;
}
