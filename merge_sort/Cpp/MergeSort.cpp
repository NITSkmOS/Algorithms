// Merge sort in C++ using recursion

#include<iostream>

using namespace std;

void merge(int a[], int p, int q, int r){
    int b[50],i = p, j = q + 1, k = 0;
    while(i <= q && j <= r){
        if(a[i] < a[j])
        	b[k++] = a[i++];    
        else
        	b[k++] = a[j++];
    }
    while(i <= q){
        b[k++] = a[i++];
	}
    while(j <= r){
    	b[k++] = a[j++];
    }
  	for(i = r; i >= p; i--){
        a[i] = b[--k];  // copying back the sorted list to a[]
	}
}

void mergesort(int a[], int p, int r ){
	int q;
    if(p < r){
    	q = (p + r)/2;
        mergesort(a,p,q);
        mergesort(a,q+1,r);
        merge(a,p,q,r);
    }
}

void display(int a[], int n){
    int i;
	for(i = 0 ;i < n; i++)
        cout<<a[i]<<"\t";
}

int main(){
	int a[50],n,i;
	cout<<"\nEnter size of Array: ";
	cin>>n;
	cout<<"\nEnter elements : ";
	for(i = 0; i < n; i++)
   		cin>>a[i];
	mergesort(a,0,n-1);
	cout<<"\nSorted Array :\t";
	display(a,n);
	return 0;
}
