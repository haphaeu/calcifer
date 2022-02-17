/*
Sorting help functions.
*/

#ifndef SORT_H
#define SORT_H

#define swap(i, j, type) {type t = i; i = j; j = t;}
int partition (double arr[], int low, int high);
void quick_sort(double arr[], int low, int high);
short is_sorted(double *v, int n);
void stupid_sort(double *v, int n);
void sort(double *v, int n);

#endif