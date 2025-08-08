// This is a program to demonstrate both linear and binary search algorithms in C.
// Linear search works on unsorted arrays, while binary search requires a sorted array.

#include <stdio.h>

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i; 
    }
    return -1; 
}

// Binary Search (works only on sorted arrays)
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid; 
        else if (arr[mid] < key)
            low = mid + 1; 
        else
            high = mid - 1; 
    }
    return -1; 
}

int main() {
    int arr[7] = {2, 4, 6, 8, 10, 12, 14}; 
    int n = 7;
    int key;

    printf("Enter number to search: ");
    scanf("%d", &key);

    int index_linear = linearSearch(arr, n, key);
    if (index_linear != -1)
        printf("Linear Search: Found at index %d\n", index_linear);
    else
        printf("Linear Search: Not found\n");

    int index_binary = binarySearch(arr, n, key);
    if (index_binary != -1)
        printf("Binary Search: Found at index %d\n", index_binary);
    else
        printf("Binary Search: Not found\n");

    return 0;
}
