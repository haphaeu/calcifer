/*
Sorting help functions.
*/

#define swap(i, j, type) {type t = i; i = j; j = t;}

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

