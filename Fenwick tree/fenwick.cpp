#include <iostream>  
using namespace std; 
  
int BITree[100005];
int getSum( int index) 
{ 
    int sum = 0;  
    index = index + 1;   
    while (index>0) 
    { 
        sum += BITree[index]; 
        index -= index & (-index); 
    } 
    return sum; 
} 
  
void updateBIT( int n, int index, int val) 
{ 
    index = index + 1; 
    while (index <= n) 
    { 
  	  	BITree[index] += val; 
    	index += index & (-index); 
    } 
} 
  
void constructBITree(int arr[], int n) 
{ 

    for (int i=1; i<=n; i++) 
        BITree[i] = 0; 
    for (int i=0; i<n; i++) 
        updateBIT( n, i, arr[i]); 
} 
  
int main() 
{ 
    
    int n,i;
    cin>>n;
    int arr[100005];
    for(i=0;i<n;i++)
	    cin>>arr[i];
    
	constructBITree(arr, n); 
  
    //example update
    arr[3] += 6; 
    updateBIT(n, 3, 6);
  
    cout << "\nSum of elements in arr[0..5] after update is "
        << getSum(5); 
  
    return 0; 
} 
