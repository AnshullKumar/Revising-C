// Simple Binary Search Program
// ------------------------------
// • Demonstrates the concept of Binary Search using arrays.
// • Binary Search repeatedly divides the search interval in half 
//   to locate the target element efficiently.
// • Works only on sorted arrays (ascending or descending order).
// • Time Complexity: O(log n)
//   Space Complexity: O(1)


#include <stdio.h>

int main() {

    int n, key, i, low, high, mid, found = 0;
    

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements (in sorted order):\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nEnter element to search: ");
    scanf("%d", &key);

    low = 0;
    high = n - 1;

    while (low <= high) {
        mid = (low + high) / 2;

        if (arr[mid] == key) {
            printf("\nElement %d found at position %d.\n", key, mid + 1);
            found = 1;
            break;
        } 
        else if (arr[mid] < key) {
            low = mid + 1;
        } 
        else {
            high = mid - 1;
        }
    }
    if (!found)
        printf("\nElement %d not found in the array.\n", key);
    return 0;
}
