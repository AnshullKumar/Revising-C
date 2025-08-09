// This file implements Bubble Sort and Bucket Sort algorithms in C.

#include <stdio.h>

// Bubble Sort
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Bucket Sort
void bucketSort(int arr[], int n) {
    int bucket[10] = {0};
    int i, j = 0;

    for (i = 0; i < n; i++) {
        bucket[arr[i]]++;
    }

    for (i = 0; i < 10; i++) {
        while (bucket[i] > 0) {
            arr[j++] = i;
            bucket[i]--;
        }
    }
}

