/*A C++ program for implementation of Heap Sort 
 By knightvertrag*/
#include <iostream> 
  
using namespace std; 
  

void heapfy(int arr[], int n, int i) 
{ 
    int largest = i;  
    int l = 2*i + 1; 
    int r = 2*i + 2; 
  
    
    if (l < n && arr[l] > arr[largest]) 
        largest = l; 
  
    
    if (r < n && arr[r] > arr[largest]) 
        largest = r; 
  
    
    if (largest != i) 
    { 
        swap(arr[i], arr[largest]); 
  
        
        heapfy(arr, n, largest); 
    } 
} 
  

void heap_Sort(int arr[], int n) 
{ 
    
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapfy(arr, n, i); 
  
    
    for (int i=n-1; i>=0; i--) 
    { 
        
        swap(arr[0], arr[i]); 
  
        
        heapfy(arr, i, 0); 
    } 
} 
  

void printArray(int arr[], int n) 
{ 
    for (int i=0; i<n; ++i) 
        cout << arr[i] << " "; 
    cout << "\n"; 
} 
  

int main() 
{ 
    int arr[] = {12, 11, 13, 5, 6, 7}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
  
    heap_Sort(arr, n); 
  
    cout << "Sorted array is \n"; 
    printArray(arr, n); 
} 