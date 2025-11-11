// Simple Linear Search Program
// ------------------------------
// • Demonstrates the concept of Linear Search using arrays.
// • Linear Search sequentially checks each element in the array until the desired key (target value) is found or the end is reached.   
// • Works on both sorted and unsorted arrays.
// • Time Complexity: O(n)
//   Space Complexity: O(1)

#include <stdio.h> 

int main() {
    int n, key, i, found = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nEnter element to search: ");
    scanf("%d", &key);

    for (i = 0; i < n; i++) {
        if (arr[i] == key) {
            printf("\nElement %d found at position %d.\n", key, i + 1);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("\nElement %d not found in the array.\n", key);

    return 0;
}
