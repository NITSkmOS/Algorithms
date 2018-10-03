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
    //Number of Elements in Array
    n = 5;
    //Array elements
    int A[n]= {1,4,8,10,15};

    //Element you want to search in array
    int element = 8;

    if(binarysearch(A,n,element))
        cout<<"Element "<<element<<" is present\n";
    else cout<<"Element is not present in Array";

    return 0;
}
