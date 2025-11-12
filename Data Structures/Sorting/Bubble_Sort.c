// Simple Bubble Sort Program
// --------------------------
// • Demonstrates the concept of Bubble Sort using arrays.
// • Bubble Sort repeatedly steps through the list, compares adjacent elements
//   and swaps them if they are in the wrong order. This process is repeated
//   until the list is sorted.
// • Time Complexity: O(n^2)
//   Space Complexity: O(1)

#include <stdio.h>

int main() {
	int n, swapped;

	printf("Enter number of elements: ");
	scanf("%d", &n);

	int arr[n];
	printf("Enter %d elements:\n", n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < n - 1; i++) {
		swapped = 0;
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				swapped = 1;
			}
		}
		if (!swapped)
			break;
	}

	printf("\nSorted array:\n");
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}

