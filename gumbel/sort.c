#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "sort.h"


/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot 
   https://www.geeksforgeeks.org/quick-sort/
*/
int partition (double arr[], int low, int high)
{
    double pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element
 
    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(arr[i], arr[j], double);
        }
    }
    swap(arr[i + 1], arr[high], double);
    return (i + 1);
}
 
/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index 
  https://www.geeksforgeeks.org/quick-sort/
*/
void quick_sort(double arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);
 
        // Separately sort elements before
        // partition and after partition
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

short is_sorted(double *v, int n) {
    for (int i=0; i<n-1; i++)
        if ( v[i] > v[i+1])
            return 0;
    return 1;
}

void stupid_sort(double *v, int n) {
    // very simple sort ascending algorithm
    // lots of room for improvement speed here
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

void sort(double *v, int n) {
    if (1)
        quick_sort(v, 0, n-1);
    else
        stupid_sort(v, n);
}

/**************************************************************************/
/*************************************************************************/
/************************************************************************/

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


/*
// Driver program to test above functions
int main()
{
    test_sort_performance();
    return 0;
}
*/