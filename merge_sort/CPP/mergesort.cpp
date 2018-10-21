#include <bits/stdc++.h>
using namespace std;
int a[1000005];

int merge(int a[], int x[], int y[], int l, int r) {
	int i,j,k;
	i = 0;
	j = 0;
	k = 0;
	while(i < l && j < r) {
		if(x[i] <= y[j]) {
			a[k++] = x[i++];
		}
		else {
			a[k++] = y[j++];
		}
	}
	while(i < l) {
		a[k++] = x[i++];
	}
	while(j < r) {
		a[k++] = y[j++];
	}
	return 0;
}

int mergesort(int a[], int n) {
	if(n<2) {
		return 0;
	}

	int mid = n/2;
	int x[mid];
	int y[n-mid];
	int i,j;
	for(i = 0;i < mid;i++) {
		x[i] = a[i];
	}
	for(j = 0;j < n-mid;j++) {
		y[j] = a[i++];
	}
	mergesort(x,mid);
	mergesort(y,n-mid);
	merge(a,x,y,mid,n-mid);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,i;
	cin>>n;
	for(i=0;i<n;i++) {
		cin>>a[i];
	}
	mergesort(a,n);
	for(i=0;i<n;i++) {
		cout<<a[i]<<' ';
	}
	cout<<endl;
	return 0;
}
