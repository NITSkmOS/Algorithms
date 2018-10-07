#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define INF 10000000000
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    long long int n,c=0,max1=0,min1=INF,max_now=0,min_now=INF;
    vector<long long int> x;
    while(cin>>n)
    {
        x.push_back(n);
        c++;
    }
    for(long long int i=0;i<c;i++)
    {
        max1=max(x[i],max1+x[i]);
        max_now=max(max1,max_now);
    }
    cout<<max_now<<endl;
    for(long long int i=0;i<c;i++)
    {
        min1=min(x[i],min1+x[i]);
        min_now=min(min1,min_now);
    }
    cout<<min_now<<endl;
    return 0;
}

