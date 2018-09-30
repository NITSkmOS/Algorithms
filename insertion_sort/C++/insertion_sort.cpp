#include<bits/stdc++.h>
using namespace std;
void insertionsort(int arr[],int n)
{
     // Fuction to do insertion sort.
    for(int i=1;i<10;i++)
    {
        int temp;
        temp=arr[i];
        int x;
        for(int j=i;j>=0;j--)
        {
            /* Move elements of arr[0..i-1], that are
           greater, to one position ahead
           of their current position */
            if(temp<=arr[j])
             {
              arr[j]=arr[j-1];
              x=j;
             }
        }
        arr[x]=temp;
    }
}
int main()
{
    int arrsize;
    arrsize=6;
    int arr[arrsize]={6,1,2,4,5,3};
    insertionsort(arr,arrsize);
    for(int i=0;i<arrsize;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
