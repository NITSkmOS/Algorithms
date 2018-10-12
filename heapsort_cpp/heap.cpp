#include<iostream>
#include"heapfunctions.h"
using namespace std;


void heap :: heapify(int arr[], int n, int i)
{
    int largest = i;  //updating largest
    int l = 2*i + 1;  // updating left
    int r = 2*i + 2;  // updating right
 
    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
 
        
        heapify(arr, n, largest);
    }
}
 
void heap :: heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    for (int i=n-1; i>=0; i--)
    {
        // Move current root to end
        swap(arr[0], arr[i]);
 
        heapify(arr, i, 0);
    }
}
 
void heap :: printArray(int arr[], int n)
{
    for (int i=0; i<n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}
