#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    //Number of Elements in Array
    n = 5;
    //Array elements
    int A[n]= {1,4,8,10,15};

    //Element you want to search in array
    int element = 8;

    if(binary_search(A,A+n,element))
        cout<<"Element "<<element<<" is present\n";
    else cout<<"Element is not present in Array";

    return 0;
}
