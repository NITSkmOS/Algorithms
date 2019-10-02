
#include <iostream>
using namespace std;
void heapify(int arr[], int m, int root)
{
   int largest = root; // root is the largest element
   int l = 2*root + 1; // left = 2*root + 1
   int r = 2*root + 2; // right = 2*root + 2
   // If left child is larger than root
   if (l < m && arr[l] > arr[largest])
   largest = l;// If right child is larger than largest so far
   if (r < m && arr[r] > arr[largest])
   largest = r;// If largest is not root
   if (largest != root)
      {
      swap(arr[root], arr[largest]);//swap root and largest
     heapify(arr, m, largest); // Recursively heapify the sub-tree
      }
}
void heapSort(int arr[], int m)
{

   for (int i = m / 2 - 1; i >= 0; i--)// build heap
   heapify(arr, m, i);
   for (int i=m-1; i>=0; i--)// extracting elements from heap one by one
   {

      swap(arr[0], arr[i]);// Move current root to end
      heapify(arr, i, 0);// again call max heapify on the reduced heap
   }
}

int main()
{
   int m ;
   cout<<"Enter totoal number of elements"<<endl;
   cin>>m;
   int ar[m];
   cout<<"Enter the array"<<endl;
   for(int i=0;i<m;i++)
	{
	   cin>>ar[i];
	}
   heapSort(ar, m);
   cout << "Sorted array is"<<endl;
   for (int i=0; i<m; ++i){
   cout << ar[i] << " ";
   cout << "\n";
   }
}
