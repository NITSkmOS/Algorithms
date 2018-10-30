#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
std::vector<int> vec;

void join(std::vector<int>& arr, int, int, int);
void sort(std::vector<int>& arr, int, int);
void show(std::vector<int>& arr);

int main() {
	int n = 10, a, i, arr[] = {2, 4, 3, 6, 5, 1, 9, 0, 8, 7};
	// cin>>n; //For custom input
	// cout<<"Enter "<<n<<" numbers (space separated): "; //For custom input
	for (i = 0; i < n; i++) {
		// cin>>a; //For custom input
		vec.push_back(arr[i]); //vec.push_back(a); // For custom input
	}
	a = 0;
	sort(vec, a, n-1);
	show(vec);
	return 0;
}

void join(std::vector<int>& arr, int l, int m, int r) {
	// Merge operation of merge sort.
	int i, j, k;
	int s1 = m-l+1, s2 = r-m;
	int L[s1], R[s2];
	for (i = 0; i < s1; i++)
		L[i] = arr[l+i];
	for (j = 0; j < s2; j++)
		R[j] = arr[m+j+1];
	i = 0; j = 0; k = l;
	while (i < s1 && j < s2) {
		if (L[i] < R[j]) {
			arr[k] = L[i];
			i++;
		} else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < s1) {
		arr[k] = L[i]; i++; k++;
	}
	while (j < s2) {
		arr[k] = R[j]; j++; k++;
	}
}

void sort(std::vector<int>& arr, int l, int r) {
	// The major implementation of merge sort algorithm
	if (l < r) {
		int m = l+(r-l)/2;
		sort(arr, l, m);
		sort(arr, m+1, r);
		join(arr, l, m, r);
	}
}

void show(std::vector<int>& arr) {
	// A basic function to view vector values
	cout << "Sorted element using Merge Sort: ";
	std::vector<int>::iterator v = arr.begin();
	while (v != arr.end()) {
		cout << *v <<" ";
		v++;
	}
	cout << endl;
}
