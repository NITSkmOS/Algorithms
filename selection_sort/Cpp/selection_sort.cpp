#include <iostream>
using namespace std;

void selection_sort(int[], int);

int main() {
	int n = 10, arr[] = {5, 7, 9, 8, 3, 1, 4, 2, 10, 6};
	selection_sort(arr, n);
	cout << "Sorted array after selection sort algorithm- ";
	for(int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}

void selection_sort(int arr[], int n) {
	//This function implements the main selection sort algorithm.
	int i, j, temp;
	for(i = 0; i < n; i++)
		for(j = i+1; j < n; j++) {
			if(arr[i] > arr[j]) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
}
