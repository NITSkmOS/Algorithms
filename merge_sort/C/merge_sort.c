#include <stdio.h>	// for printf function

// Function prototypes
void mergesort(int[], int, int);
void merge(int[], int, int, int);

int main() {
	int arr_size = 6;
	int arr[] = {10, 9, 8, 7, 6, 5};
	mergesort(arr, 0, arr_size);

	// Print sorted array
	for (int i = 0; i < arr_size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}

/*
 * Recursively split the array and call the merge function
 * Main entry point of Merge Sort
 */
void mergesort(int arr[], int l, int r) {
	if(l >= r)
		return;
	int m = (l + r) / 2;
	mergesort(arr, l, m);
	mergesort(arr, m+1, r);
	merge(arr, l, m, r);
}

// Merges the arrays in ascending order of elements
void merge(int arr[], int l, int m, int r) {
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	int L[n1], M[n2];

	for(i = 0; i < n1; ++i)
		L[i] = arr[l+i];
	for(j = 0; j < n2; ++j)
		M[j] = arr[m + 1 + j];

	i = 0;
	j = 0;
	k = l;

	while(i < n1 && j < n2) {
		if(L[i] <= M[j]) {
			arr[k] = L[i];
			++i;
		} else {
			arr[k] = M[j];
			++j;
		}
		++k;
	}

	while(i < n1) {
		arr[k] = L[i];
		++i;
		++k;
	}

	while(j < n2) {
		arr[k] = M[j];
		++j;
		++k;
	}
}
