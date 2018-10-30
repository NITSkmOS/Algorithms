#include <iostream>
using namespace std;


void swap(int& a, int& b)
{
  int t=a;
  a=b;
  b=t;
}

int partition(int input[], int n)
{
  int p=input[0];
  int count=0;
  for(int i=0;i<n;i++)
    if(input[i]<p)
      count++;
  swap(input[0],input[count]);
  int i=0,j=n-1;
  while(i<count&&j>count)
  {
    if(input[i]<p)
      i++;
    else if(input[j]>=p)
      j--;
    else
    {
      swap(input[i],input[j]);
      i++;
      j--;
    }
  }
  return count;
}

void quickSort(int input[], int n) {
  if(n==0||n==1)
    return;
  else
  {
    int p=partition(input,n);
    quickSort(input,p);
    quickSort(input+p+1,n-p-1);
  }

}

int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];

	quickSort(arr,n);
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
}