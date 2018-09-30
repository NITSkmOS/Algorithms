#include <bits/stdc++.h>
using namespace std;
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
    if(binary_search(A,A+n,element))
        cout<<"Element is present\n";
    else cout<<"Element is not present in Array";

    return 0;
}
