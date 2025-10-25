// Dynamic Array Program in C:
// - Allocates an array dynamically using malloc and allows resizing with realloc.
// - Supports insertion of elements at any position by shifting existing elements.
// - Supports deletion of elements and shrinks the array accordingly.
// - Allows searching for elements using Linear or Binary search.
// - Displays the array and provides a menu-driven interface for user interaction.


#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr = NULL, n = 0, choice, key, pos, i;

    printf("Enter no of elements in the array: ");
    scanf("%d", &n);

    arr = (int*) malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 0;
    }

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Insert Element\n");
        printf("2. Delete Element\n");
        printf("3. Search Element\n");
        printf("4. Display Array\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {  
            int val, pos;
            printf("Enter element to insert: ");
            scanf("%d", &val);
            printf("Enter position (0 to %d): ", n);
            scanf("%d", &pos);

            arr = (int*) realloc(arr, (n + 1) * sizeof(int));
            if (arr == NULL) {
                printf("Memory reallocation failed!\n");
                return 0;
            }

            for (i = n; i > pos; i--)
                arr[i] = arr[i - 1];
            arr[pos] = val;
            n++;

            printf("Element inserted!\n");
        }
        else if (choice == 2) {  
            if (n == 0) {
                printf("Array is empty!\n");
                continue;
            }
            printf("Enter position to delete (0 to %d): ", n - 1);
            scanf("%d", &pos);

            if (pos < 0 || pos >= n) {
                printf("Invalid position!\n");
                continue;
            }

            for (i = pos; i < n - 1; i++)
                arr[i] = arr[i + 1];

            n--;
            arr = (int*) realloc(arr, n * sizeof(int));
            printf("Element deleted!\n");
        }

        else if (choice == 3) {  
            int method;
            printf("Enter element to search: ");
            scanf("%d", &key);

            printf("Choose search method:\n1. Linear Search\n2. Binary Search\n");
            scanf("%d", &method);

            pos = -1;

            if (method == 1) {     // Linear Search
                for (i = 0; i < n; i++) {
                    if (arr[i] == key) {
                        pos = i;
                        break;
                    }
                }
            } else if (method == 2) {     // Binary Search
                int l = 0, r = n - 1;
                while (l <= r) {
                    int mid = (l + r) / 2;
                    if (arr[mid] == key) { pos = mid; break; }
                    else if (arr[mid] < key) l = mid + 1;
                    else r = mid - 1;
                }
            } else {
                printf("Invalid method!\n");
                continue;
            }

            if (pos != -1)
                printf("Element found at position %d (index %d)\n", pos + 1, pos);
            else
                printf("Element not found!\n");
        }

        else if (choice == 4) {  // Display
            if (n == 0) printf("Array is empty!\n");
            else {
                printf("Array: ");
                for (i = 0; i < n; i++)
                    printf("%d ", arr[i]);
                printf("\n");
            }
        }

        else if (choice == 5) {  // Exit
            free(arr);
            printf("Exiting...\n");
            break;
        }

        else {
            printf("Invalid choice!\n");
        }
    }

    return 0;
}