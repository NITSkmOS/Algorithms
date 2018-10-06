#include <iostream>
using namespace std;

void countingSort(int arr[],int n,int RANGE){
    int count[RANGE]={0};
    int i;
    int out[n];
    
    
    for(i=0;i<n;i++)
    ++count[arr[i]];
    
    for(i=1;i<RANGE;i++)
    count[i]+=count[i-1];
    
   
    
    for(i=n-1;i>=0;i--){
        out[count[arr[i]]-1]=arr[i];
        --count[arr[i]];
    }
    
    for(i=0;i<n;i++)
    arr[i]=out[i];
    
    
    
}
void print(int arr[],int n){
    cout<<"array : ";
    for(int i=0;i<n;i++)
    cout<<arr[i]<<' ';
    cout<<endl;
}

int main() {
	// your code goes here
	int arr[]={1, 4, 1, 2, 7, 5, 2};
	int n=sizeof(arr)/sizeof(arr[0]);
	int RANGE=9;
	
	print(arr,n);
	
	countingSort(arr,n,RANGE);
	
    print(arr,n);
	
	return 0;
}
