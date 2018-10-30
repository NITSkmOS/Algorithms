#include <iostream>
using namespace std;


void merge(int a[], int n1, int b[], int n2, int arr[])
{
  int i=0,j=0,k=0;
  cout<<endl;
  while(i<n1)
  {
  	cout<<a[i]<<" ";
  	i++;
  }
  cout<<endl;
  while(j<n2)
  {
  	cout<<b[j]<<" ";
  	j++;
  }
i=0;j=0;
  while(i<n1&&j<n2)
  {
    if(a[i]<b[j])
    {
      arr[k]=a[i];
      i++;
    }
    else
    {
      arr[k]=b[j];
      j++;
    }
    k++;
  }
  while(i<n1)
  {
    arr[k]=a[i];
    k++;
    i++;
  }
  while(j<n2)
  {
    arr[k]=b[j];
    k++;
    j++;
  }
}
void mergeSort(int input[], int n){
	
  if(n==0||n==1)
    return;
  else
  {
    int mid=(n-1)/2;
    int n1=mid+1;
    int n2=n-mid-1;
    int a[n1],b[n2];
    for(int i=0;i<n1;i++)
      {
      	a[i]=input[i];
      }
    int k=0;
    for(int j=mid+1;j<n;j++)
    {
      b[k]=input[j];
      k++;
    }
    mergeSort(a,n1);
    mergeSort(b,n2);
    merge(a,n1,b,n2,input);
  }
        
}
int main()
{
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++)
    cin>>arr[i];

  mergeSort(arr,n);
  for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
}


