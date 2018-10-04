#include<iostream>
using namespace std;
int partition_array(int a1[],int low1,int high1)
{
    int pivot=a1[high1],j=low1,temp,i;
    for(i=low1;i<high1;i++)
    {
        if(a1[i]>pivot)
            continue;
        else
        {
            temp=a1[i];
            a1[i]=a1[j];
            a1[j]=temp;
            j++;
        }
    }
    temp=a1[j];
    a1[j]=a1[high1];
    a1[high1]=temp;
    return j;

}
void quicksort(int a2[],int low2,int high2)
{
    if(low2<high2)
    {
        int pivot_index=partition_array(a2,low2,high2);
        quicksort(a2,low2,pivot_index-1);
        quicksort(a2,pivot_index+1,high2);
    }
}
int main()
{
    int n;
    cout<<"Number Of Elements: ";
    cin>>n;
    int a[n],i;
    cout<<"Elements Of Array: ";
    for(i=0;i<n;i++)
        cin>>a[i];
    quicksort(a,0,n-1);
    cout<<"Sorted Array Is: ";
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}
