#include <stdio.h>
#include <math.h>

void insertion_sort(int arr[], int n) {
	// Fuction to do insertion sort.
	int i;
	int pivot;
	int j;
	for (i = 1; i < n; i++) {
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

void printArray(int arr[], int n) 
{ 
    int i; 
    for (i = 0; i < n; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 

int main() {
	int arr[6] = {6, 5, 4, 3, 2, 1};
	int n= sizeof(arr)/ sizeof(arr[0]);
	insertion_sort(arr, n);
	printArray(arr, n);

	return 0;
}
