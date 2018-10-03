#include <stdio.h>

#define SIZE 100000

int arr[SIZE] = {};
int tmp[SIZE] = {};

void merge(int l, int m, int r) {
	int i=l, j=m+1, c=l;
	while(i<=m && j<=r) {
		if(arr[i] < arr[j]) tmp[c++] = arr[i++];
		else tmp[c++] = arr[j++];
	}
	while(i<=m) tmp[c++] = arr[i++];
	while(j<=r) tmp[c++] = arr[j++];
	for(i=l;i<=r;i++) arr[i] = tmp[i];
}

void msort(int l, int r) {
	if(l < r) {
		int m = l + (r-l)/2;
		msort(l, m);
		msort(m+1, r);
		merge(l, m, r);
	}
}

int main() {
	int n = 10;
	for(int i=0;i<n;i++) {
		arr[i] = n-i;
	}
	msort(0, n-1);
	for(int i=0;i<n;i++) {
		printf("%d ", arr[i]);
	}
}