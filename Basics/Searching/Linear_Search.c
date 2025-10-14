// Simple Linear Search Program
// ----------------------------
// • Searches for an element in an array with Time Complexity O(n).

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
