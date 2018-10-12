#include <iostream>
#include<bits/stdc++.h>
#include "heapfunctions.h"
using namespace std;
heap h;
 
int main(int argc,char* argv[])
{

	time_t seed;
	int i,n;
	seed=atoi(argv[1]);
	srand(time(&seed));
	n=atoi(argv[2]);
     	int arr[n];
     	for(i=0;i<n;i++)
     		arr[i]=rand()%1000;
    	h.heapSort(arr, n);
    	cout <<"Sorted array is \n";
    	h.printArray(arr, n);
}
