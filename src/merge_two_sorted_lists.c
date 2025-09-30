/**
 * LeetCode Problem 21: Merge Two Sorted Lists
 * Student: Harsh Dalal
 * Date: September 30, 2025
 * 
 * Problem: Merge two sorted arrays into one sorted array
 * Since we're working with arrays instead of linked lists in C for this assignment,
 * I've adapted it to merge two sorted integer arrays.
 * 
 * What I learned:
 * - The two-pointer technique is really efficient for merging sorted sequences
 * - Similar logic to what we use in merge sort's merge function
 * - Important to handle remaining elements after main merge loop
 * - Need to be careful with array bounds and memory allocation in C
 * 
 * Compared with other solutions:
 * - Most solutions online use linked lists, but the array version is cleaner
 * - Some solutions create the result array dynamically, I used static allocation
 * - The logic is nearly identical to our merge sort's merge function
 */

#include <stdio.h>
#include <stdlib.h>

// Function to merge two sorted arrays into a result array
// Returns the size of the merged array
int mergeSortedArrays(int arr1[], int size1, int arr2[], int size2, int result[]) {
    int i = 0;  // pointer for first array
    int j = 0;  // pointer for second array
    int k = 0;  // pointer for result array
    
    // merge while both arrays have elements
    while (i < size1 && j < size2) {
        if (arr1[i] <= arr2[j]) {
            result[k++] = arr1[i++];
        } else {
            result[k++] = arr2[j++];
        }
    }
    
    // copy remaining elements from arr1 if any
    while (i < size1) {
        result[k++] = arr1[i++];
    }
    
    // copy remaining elements from arr2 if any
    while (j < size2) {
        result[k++] = arr2[j++];
    }
    
    return k;  // return the size of merged array
}

// helper function to print array
void printArray(int arr[], int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n");
}

int main() {
    // Test case 1: Regular merge
    int arr1[] = {1, 3, 5, 7, 9};
    int arr2[] = {2, 4, 6, 8, 10};
    int result1[10];
    
    printf("Test Case 1:\n");
    printf("Array 1: ");
    printArray(arr1, 5);
    printf("Array 2: ");
    printArray(arr2, 5);
    
    int mergedSize = mergeSortedArrays(arr1, 5, arr2, 5, result1);
    printf("Merged:  ");
    printArray(result1, mergedSize);
    printf("\n");
    
    // Test case 2: Different sizes
    int arr3[] = {1, 5, 10};
    int arr4[] = {2, 3, 4, 11, 12, 13};
    int result2[9];
    
    printf("Test Case 2:\n");
    printf("Array 1: ");
    printArray(arr3, 3);
    printf("Array 2: ");
    printArray(arr4, 6);
    
    mergedSize = mergeSortedArrays(arr3, 3, arr4, 6, result2);
    printf("Merged:  ");
    printArray(result2, mergedSize);
    printf("\n");
    
    // Test case 3: One empty array
    int arr5[] = {1, 2, 3};
    int arr6[] = {};
    int result3[3];
    
    printf("Test Case 3:\n");
    printf("Array 1: ");
    printArray(arr5, 3);
    printf("Array 2: ");
    printArray(arr6, 0);
    
    mergedSize = mergeSortedArrays(arr5, 3, arr6, 0, result3);
    printf("Merged:  ");
    printArray(result3, mergedSize);
    printf("\n");
    
    // Test case 4: Arrays with duplicates
    int arr7[] = {1, 3, 3, 5};
    int arr8[] = {2, 3, 4, 5};
    int result4[8];
    
    printf("Test Case 4:\n");
    printf("Array 1: ");
    printArray(arr7, 4);
    printf("Array 2: ");
    printArray(arr8, 4);
    
    mergedSize = mergeSortedArrays(arr7, 4, arr8, 4, result4);
    printf("Merged:  ");
    printArray(result4, mergedSize);
    
    return 0;
}

/**
 * Time Complexity: O(m + n) where m and n are sizes of the two arrays
 * Space Complexity: O(m + n) for the result array
 * 
 * This is optimal since we need to look at every element at least once
 * and we need space to store all elements in the result.
 */
