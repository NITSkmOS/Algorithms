#include <stdio.h>	// for printf function

void selection_sort(int[], int);
void print_array(int[], int);

int main() {
	int arr[] = {4, 3, 42, 82, 5, 2, 33};
	int n = sizeof(arr) / sizeof(arr[0]);
	selection_sort(arr, n);
	printf("Sorted array is: ");
	print_array(arr, n);
	printf("\n");
	return 0;
}

/* Function to print array */
void print_array(int arr[], int n) {
	for (int i = 0; i < n; ++i) {
		printf("%d ", arr[i]);
	}
}

/* Selection Sort algorithm */
void selection_sort(int arr[], int n) {
	for (int i = 0; i < n - 1; ++i) {
		int small = i;
		for (int j = i + 1; j < n; ++j) {
			if (arr[j] < arr[small])
				small = j;
		}
		int temp = arr[i];
		arr[i] = arr[small];
		arr[small] = temp;
	}
}
