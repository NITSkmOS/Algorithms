#include <stdio.h>

int binarySearch(int arr[], int start, int end, int item)
{
	int mid = start + (end-start) / 2;
	while (start <= mid) {
		if (arr[mid] == item) {
			return mid;
		} else if (arr[mid] > item) {
			end = mid-1;
		} else {
			start = mid+1;
		}
		mid = start + (end-start) / 2;
	}
	return -1;
}

int main()
{
	int arr[] = {1, 3, 4, 4, 10, 13, 25, 26, 27, 60};
	int n = 10;
	int x = 13;
	int result = binarySearch(arr, 0, n - 1, x);
	printf("Index of %d in array is: %d\n", x, result);
	return 0;
}
