#include <stdio.h>
#include <stdlib.h>

int binary_search (int* arr, int start, int end, int val) {
	int mid = (start + end) / 2;
	if (start <= end) {
		if (arr[mid] == val) {
			return mid;
		} else if (arr[mid] > val) {
			return binary_search(arr, start, mid - 1, val);
		} else {
			return binary_search(arr, mid + 1, end, val);
		}
	}

	return -1;
}

int main(int argc, char ** argv) {
	int arr[] = {10, 12, 21, 66, 90, 99};

	int size = sizeof(arr) / sizeof(int);
	int n = atoi(argv[1]);

	int index = binary_search(arr, 0, size, n);

	printf("Index of %d is %d\n", n, index);

	return 0;
}