#ifndef SORTS_H
#define SORTS_H

#include <stdlib.h>
#include "sort_helper.h"

/*** code for selection sort ****/

// Returns the minimum integer from a range in an array
// Input: array - An array of integers
//        start - Where to start looking in an array
//        stop - End of where to search. Typically the 'size' of the array.
// Output: The index in an array of the minimum value between a range [start,stop]
int findMinimum(int *array, int start, int stop)
{
    // initialize min_index to the start position
    int min_index = start;
    // loop through array from start+1 to stop
    for(int i = start + 1; i < stop; i++) {
        // if current element is less than element at min_index
        if(array[i] < array[min_index]) {
            // update min_index to current position
            min_index = i;
        }
    }
    return min_index; // return the index of minimum value
}


// =============== Sort Function ===============
// Provided below is a sort function. I have also
// provided a template for how to document functions
// to help organize your code.
// Name: sort
// Input(s):
//  - 'array' is a pointer to an integer address.
//     This is the start of some 'contiguous block of memory' that we will sort.
//  - 'size' tells us how big the array of data is we are sorting.
//  -  'print' tells it to print out after each interation
// Output: No value is returned, but 'array' should be modified to store a sorted array of numbers.
void selectionSortIntegers(int *array, unsigned int size, int print)
{
    // handle empty or single element array
    if(size <= 1) return;
    
    // outer loop goes through each position in array
    for(unsigned int i = 0; i < size - 1; i++) {
        // find the minimum element in unsorted portion
        int min_idx = findMinimum(array, i, size);
        // swap the found minimum with first element of unsorted portion
        if(min_idx != i) {
            swap(&array[i], &array[min_idx]);
        }
        // print array if requested after each outer loop iteration
        if(print) {
            printIntArray(array, size);
        }
    }
}

/***  Code for Insertion Sort ***/

// =============== Sort Function ===============
// Provided below is a sort function. I have also
// provided a template for how to document functions
// to help organize your code.
// Name: sort
// Input(s):
//  - 'array' is a pointer to an integer address.
//     This is the start of some 'contiguous block of memory' that we will sort.
//  - 'size' tells us how big the array of data is we are sorting.
//  - 'print' tells it to print out after each iteration 
// Output: No value is returned, but 'array' should be modified to store a sorted array of numbers.
void insertionSortIntegers(int *array, unsigned int size, int print)
{
    // handle empty or single element array
    if(size <= 1) return;
    
    // start from the second element (index 1)
    for(unsigned int i = 1; i < size; i++) {
        // store current element to be inserted
        int key = array[i];
        // start comparing with elements before it
        int j = i - 1;
        
        // shift elements greater than key to the right
        while(j >= 0 && array[j] > key) {
            array[j + 1] = array[j];  // shift element to right
            j = j - 1;  // move to previous element
        }
        // insert key at correct position
        array[j + 1] = key;
        
        // print array if requested after each insertion
        if(print) {
            printIntArray(array, size);
        }
    }
}

/** Code for Bubble Sort (from Lab -if not compiling, comment out the internals, but leave the function definition) ***/

// =============== Sort Function ===============
// Name: bubblesort
// Desc: O(n^2) comparison sort
// param(1): 'array' is a pointer to an integer address.
//           This is the start of some 'contiguous block of memory'
//           that we will sort.
// param(2)  'size' tells us how big the array of
//           data is we are sorting.
// param(3) 'print' tells it to print out after each iteration.
// Output:   No value is returned, but 'array' should
//           be modified to store a sorted array of size.
void bubbleSortIntegers(int *array, unsigned int size, int print)
{
    // handle empty or single element array
    if(size <= 1) return;
    
    // outer loop for number of passes
    for(unsigned int i = 0; i < size - 1; i++) {
        // flag to check if any swap happened
        int swapped = 0;
        // inner loop for comparisons in each pass
        for(unsigned int j = 0; j < size - i - 1; j++) {
            // compare adjacent elements
            if(array[j] > array[j + 1]) {
                // swap if out of order
                swap(&array[j], &array[j + 1]);
                swapped = 1;
            }
        }
        // print after each pass if requested
        if(print) {
            printIntArray(array, size);
        }
        // if no swaps happened, array is sorted
        if(!swapped) break;
    }
}

// ** You will work on merge sort during the lab on Module 06 ** //

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int temp[], int l, int m, int r)
{
    if (arr == NULL || temp == NULL)
    {
        exit(1);
    }

    if (l > m || m + 1 > r)
        return;

    int i = l;      // starting index of left subarray
    int j = m + 1;  // starting index of right subarray
    int k = l;      // starting index to be sorted
    
    // merge the two subarrays
    while(i <= m && j <= r) {
        if(arr[i] <= arr[j]) {
            temp[k] = arr[i];
            i++;
        } else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }
    
    // copy remaining elements of left subarray if any
    while(i <= m) {
        temp[k] = arr[i];
        i++;
        k++;
    }
    
    // copy remaining elements of right subarray if any
    while(j <= r) {
        temp[k] = arr[j];
        j++;
        k++;
    }
    
    // copy the sorted subarray back to original array
    for(i = l; i <= r; i++) {
        arr[i] = temp[i];
    }
}

// To be built during week 6 lab
// Name: mergeSort
// Input(s):
//          (1) 'arr' is a pointer to an integer address.
//              This is the start of some 'contiguous block of memory' that we will sort.
//          (2) 'temp' is a pointer to an integer address.
//          	This helps temporarily store the sorted subarray.
//          (3) 'l' and 'r' are integers, which are the first index and the last index of 'arr' respectively.
// Output: No value is returned, but 'array' should be modified to store a sorted array of numbers.
void merge_sort(int arr[], int temp[], int l, int r)
{
    // base case - if left index is less than right
    if(l < r) {
        // find the middle point
        int m = l + (r - l) / 2;
        
        // recursively sort first half
        merge_sort(arr, temp, l, m);
        
        // recursively sort second half
        merge_sort(arr, temp, m + 1, r);
        
        // merge the sorted halves
        merge(arr, temp, l, m, r);
    }
}

// lab build, merge sort

void mergeSortIntegers(int *array, unsigned int size, int print)
{ // print is ignored for this one
    if (array == NULL)
    {
        exit(1);
    }
    if (size <= 1)
        return;

    int *temp = (int *)malloc(sizeof(int) * size);
    merge_sort(array, temp, 0, size - 1);
    free(temp);
}

// provided code 

// =============== Helper Functions ===============
// Name:    compare
// Desc:    A compare function which returns
//          a value (positive,negative, or 0)
//          to show if the result is >,<, or =.
//
// Input:   a and b here are generic types,
//          that is why they are 'void'
int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

void quickSortIntegers(int* array, unsigned int size, int print) 
{   // print is ignored as qsort doesn't use it
    qsort(array, size, sizeof(int), compare);
}

#endif
