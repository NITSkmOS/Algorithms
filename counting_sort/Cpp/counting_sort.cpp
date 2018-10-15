#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

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

	int *cnt = new int[r+1]; //array to store count of each occurences
	int *out = new int[n]; //Out array to store sorted values


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
	ios_base::sync_with_stdio(false); //For faster io
	int a[] = {1, 2, 9, 293, 41, 15, 52, 3, 121, 7, 1223, 3449, 15, 1 };
	int n = sizeof(a)/sizeof(a[0]);

	// Get the iterator to max element for calculating range of number
	int * max_a_itr = max_element(a, a+n);
	int max_a = *max_a_itr;


	cout << "Input Array:\n";
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << "\n";

	counting_sort(a, n, max_a);

	cout << "Sorted Array:\n";
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << "\n";

	return 0;
}
