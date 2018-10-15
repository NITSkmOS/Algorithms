#include <stdio.h>

void quick_sort(int[], int, int);
void print_array(int[], int);
int partition(int[], int, int);
void swap(int*, int*);

int main() {
	int arr[] = {45, 92, 54, 23, 6, 4, 12};
	int n = sizeof(arr) / sizeof(arr[0]);
	quick_sort(arr, 0, n);
	printf("Sorted array: \n");
	print_array(arr, n);
}

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

/* Quick Sort algorithm */
void quick_sort(int arr[], int lb, int ub) {
	if (lb < ub) {
		int pi = partition(arr, lb, ub);

		quick_sort(arr, lb, pi - 1);
		quick_sort(arr, pi + 1, ub);
	}
}

/* Partitioning function */
int partition(int arr[], int low, int high) {
	int i = low + 1;
	int piv = arr[low];

	for (int j = low + 1; j <= high; ++j) {
		if (arr[j] < piv) {
			swap(&arr[i], &arr[j]);
			i++;
		}
	}
	swap(&arr[low], &arr[i - 1]);
	return i - 1;
}

/* Function to print array */
void print_array(int arr[], int size) {
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}
