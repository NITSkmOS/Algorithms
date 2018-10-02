#include <bits/stdc++.h>
using namespace std;
bool binarysearch(const int A[],int n, int ele)
{
    int low = 0, high = n-1, mid;
    while(low<=high)
    {
        mid = (low+high)/2;
        if(A[mid]==ele)
            return true;
        else if(A[mid]>ele)
        {
            high = mid-1;
        }
        else low = mid+1;
    }
    return false;
}
int main()
{
    int n;
    cout<<"Enter number of elements in Array:";
    cin>>n;
    int *A = new int[n];
    cout<<"Enter elements of Array(Sorted)\n";
    for(int i=0;i<n;i++)
        cin>>A[i];

    int element;
    cout<<"Enter element which you want to search\n";
    cin>>element;
    if(binarysearch(A,n,element))
        cout<<"Element is present\n";
    else cout<<"Element is not present in Array";

    return 0;
}
