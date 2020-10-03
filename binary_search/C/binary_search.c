#include <stdio.h>

int binary_search(int arr[], int start, int end, int target) {
	while (start <= end) {
		int mid = start + (end - start) / 2;
		if (arr[mid] == target) {
			return mid;
		} else if (arr[mid] > target) {
			end = mid - 1;
		} else {
			start = mid + 1;
		}
	}
	return -1;
}

int main(void) {
	int arr[] = {-1, 0, 3, 4, 5, 6, 7, 8, 9};
	int n = sizeof(arr) / sizeof(arr[0]);
	int target = -1;
	int result = binary_search(arr, 0, n - 1, target);
	printf("Index of %d in array is: %d \n", target, result);
	return 0;
}
