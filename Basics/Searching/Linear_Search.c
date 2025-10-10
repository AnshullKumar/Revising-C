// Simple Linear Search Program
// ----------------------------
// • Demonstrates Linear Search on an array.
// • Works on both sorted and unsorted data.
// • Traverses the entire array to find a key.
// • Returns the position if found, otherwise displays "not found".

#include <stdio.h>

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i;  // Return index if found
    }
    return -1;  // Return -1 if not found
}

int main() {
    int arr[] = {25, 10, 45, 30, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 30;

    int pos = linearSearch(arr, n, key);
    if (pos != -1)
        printf("Element %d found at position %d\n", key, pos + 1);
    else
        printf("Element %d not found\n", key);

    return 0;
}
