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

    }
}