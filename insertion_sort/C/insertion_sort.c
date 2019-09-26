#include <stdio.h>
#include <math.h>

void insertion_sort(int arr_size, int arr[]) {
	// Fuction to do insertion sort.
	int i;
	int pivot;
	int j;
	for (i = 1; i < arr_size; i++) {
		pivot = arr[i];
		j = i-1;
		/* Move elements of arr[0..i-1], that are
		* greater than pivot, to one position ahead
		* of their current position */
		while (j >= 0 && arr[j] > pivot) {
			arr[j+1] = arr[j];
			j = j-1;
		}
		arr[j+1] = pivot;
	}
}

int main() {
	int i;
	int arr[6] = {6, 5, 4, 3, 2, 1};
	int arr_size= sizeof(arr)/ sizeof(arr[0]);
	insertion_sort(arr, arr_size );
	for (i=0; i < arr_size; i++) {
		printf("%d\n", arr[i]);
	}
	return 0;
}
