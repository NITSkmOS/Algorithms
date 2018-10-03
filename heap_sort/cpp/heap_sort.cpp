#include <iostream>

using namespace std;

inline void swap(int &a, int &b) {
	int t = a;
	a = b;
	b = t;
}

void heapify(int ar[], int i, int n) {
	int left = 2*i;
	int right = left + 1;
	int least = i;
	if(left <= n && ar[left] > ar[i])
		least = left;
	else if(right <= n && ar[right] > ar[least])
		least = right;
	if(least != i) {
		swap(ar[i], ar[least]);
		heapify(ar, least, n);
	}
}

void build(int ar[], int n) {
	for(int i=n/2;i>0;--i) {
		heapify(ar, i, n);
	}
}

void heap_sort(int ar[], int n) {
	build(ar, n);
	for(int i=n; i > 1; --i) {
		swap(ar[1], ar[i]);
		--n;
		heapify(ar, 1, n);
	}
}

int main() {
	int n;
	cin >> n;
	int ar[n+1];
	for(int i=1;i<=n;++i)
		cin >> ar[i];
	heap_sort(ar, n);
	for(int i=1;i<=n;++i)
		cout << ar[i] << " ";
	cout << endl;

	return 0;
}