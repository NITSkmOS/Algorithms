#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

/*
Utility function for Radix sort to sort given array for dth digit.
This is essentially modified version of counting sort.

Parameters:
int a[] - Integer array a to be sorted.
int n	- size of array a.
int d	- Digit by which to sort the array with (0 based indexing).
*/

void radix_digit_util(int a[], int n, int d) {
	if(a == NULL) return;

	int exp = pow(10, d);

	int *cnt = new int[10]; //array to store count of each occurences
	int *out = new int[n]; //Out array to store sorted values

	// Intitialise the count array to 0
	for (int i = 0; i < n; ++i)
		cnt[i] = 0;

	// Count each occurences digit wise
	for (int i = 0; i < n; ++i)
		cnt[(a[i]/exp)%10]++;

	// Cumulative count array
	for (int i = 1; i < n; ++i)
		cnt[i]+=cnt[i-1];

	// Sort
	for (int i = n - 1; i >= 0; i--) {
	// Note - starting from n-1 to maintain "stable sort" property
		out[cnt[(a[i]/exp)%10] - 1] = a[i];
		cnt[(a[i]/exp)%10]--;
	}

	// Copy results back to orignal array
	for (int i = 0; i < n; i++)
		a[i] = out[i];
}


/*
Radix sort implementation for sorting given array assuming the base 10.
Note - // Works on Non-negative integer array only.

Parameters:
int a[] - Non-negative Integer array a to be sorted.
int n	- size of array a.
*/
void radix_sort(int a[], int n) {
	if(a == NULL) return;

	// Get the iterator to max element for calculating maximum number of digits.
	int * max_a_itr = max_element(a, a+n);
	int max_a = *max_a_itr;

	// Get maximum number of digits of all elements in array a
	int max_d = 0;
	while(max_a) {
		max_d++;
		max_a = max_a/10;
	}

	// Sort the array digit wise starting from lowest significant digit to highest.
	for (int d = 0; d < max_d; d++)
		radix_digit_util(a, n, d);
}


int main() {
	ios_base::sync_with_stdio(false); //For faster io
	int a[] = {1, 2, 9, 293, 41, 15, 52, 3, 121, 7, 1223, 3449, 15, 1 };
	int n = sizeof(a)/sizeof(a[0]);

	cout << "Input Array:\n";
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << "\n";

	radix_sort(a, n);

	cout << "Sorted Array:\n";
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << "\n";

	return 0;
}
