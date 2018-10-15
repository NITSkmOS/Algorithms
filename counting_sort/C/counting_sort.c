#include <stdio.h>
#include <stdlib.h>

/*
Counting sort implementation for sorting given array.
Note - Works on Non-negative integer array only.

Parameters:
int a[] - Integer array a to be sorted.
int n	- size of array a.
int r.	- Range of numbers in a.
*/

void counting_sort(int a[], int n, int r) {
	if(a == NULL) return;

	//array to store count of each occurences
	int *cnt = (int *) malloc((r+1)*sizeof(int));  // Ignore CPPLintBear
	//Out array to store sorted values
	int *out = (int *) malloc((n)*sizeof(int));  // Ignore CPPLintBear


	// Intitialise the count array to 0
	for (int i = 0; i <= r; ++i)
		cnt[i] = 0;

	// Count each occurences digit wise
	for (int i = 0; i < n; ++i)
		cnt[a[i]]++;

	// Cumulative count array
	for (int i = 1; i <= r; ++i)
		cnt[i]+=cnt[i-1];

	// Sort
	for (int i = n - 1; i >= 0; i--) {
		// Note - starting from n-1 to maintain "stable sort" property
		out[cnt[a[i]] - 1] = a[i];
		cnt[a[i]]--;
	}

	// Copy results back to orignal array
	for (int i = 0; i < n; i++)
		a[i] = out[i];
}


int main() {
	int a[] = {1, 2, 9, 293, 41, 15, 52, 3, 121, 7, 1223, 3449, 15, 1 };
	int n = sizeof(a)/sizeof(a[0]);

	// Get the max element for calculating range of number
	int max_a = a[0];
	for (int i = 1; i < n; ++i)
		if(max_a < a[i]) max_a = a[i];


	printf("Input Array:\n");
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");

	counting_sort(a, n, max_a);

	printf("Sorted Array:\n");
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");

	return 0;
}
