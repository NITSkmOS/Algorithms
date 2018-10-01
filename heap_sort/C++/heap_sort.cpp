#include <iostream> 
  
using namespace std; 

void heapify(int input[], int n, int i) 
{ 
    int largest = i; 
    int left = 2*i + 1; 
    int right = 2*i + 2; 
  
    if (left < n && input[left] > input[largest]) 
        largest = left; 
  
    if (right < n && input[right] > input[largest]) 
        largest = right; 
        
    if (largest != i) 
    { 
        swap(input[i], input[largest]); 
  
        heapify(input, n, largest); 
    } 
} 
  
void heapSort(int input[], int n) 
{ 
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(input, n, i); 
    for (int i=n-1; i>=0; i--) 
    { 
        swap(input[0], input[i]); 
        heapify(input, i, 0); 
    } 
} 
int main() 
{   
    int n;
    cout<<"Enter the number of elements"<<endl;
    cin>>n;
    int array[n];
    cout<<"Enter the elements of array"<<endl;
    
    for(int i=0; i<n; i++){
        cin>>array[i];
    }
    heapSort(array, n); 
    cout << "Sorted array is \n"; 
    for(int i=0; i<n; i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
    return 1;
} 