#include<bits/stdc++.h>
using namespace std;

int euclidean_gcd_division_based(int a,int b)
{
    /*
     * Calculates gcd of two numbers using iterative euclid division method
     */
    while(b!=0)
    {
        int remainder=a%b;
        a=b;
        b=remainder;
    }
    return a;
}

int euclidean_gcd_recursive(int a,int b)
{
    /*
     * Calculates gcd of two numbers using recursive euclid method
     */
    if(b==0)
    {
        return a;
    }
    return euclidean_gcd_recursive(b,a%b);
}

int extended_euclidean_gcd(int a,int b,int &x,int &y)
{
    /*
     * Calculates gcd of two numbers using extended euclid method
     * with weights in linear combination calculated simultaneously
     */
    if(b==0)
    {
        return extended_euclidean_gcd(b,a,x,y);
    }
    if(a%b==0)
    {
        x=0;
        y=1;
        return b;
    }
    int gcd=extended_euclidean_gcd(b,a%b,x,y);
    int tmp=x;
    x=y;
    y=tmp-(a/b)*y;
    return gcd;
}

int main()
{
    int a=132,b=24;
    int x,y;//For linear combination weights in extended euclidean gcd
    if(a>=0 && b>=0)
    {
        cout<<"Division Based GCD Output for ("<<a<<","<<b<<"):"<<euclidean_gcd_division_based(a,b);
        cout<<endl;
        cout<<"Recursive GCD Output for ("<<a<<","<<b<<"):"<<euclidean_gcd_recursive(a,b);
        cout<<endl;
        cout<<"Extended GCD Output for ("<<a<<","<<b<<"):"<<extended_euclidean_gcd(a,b,x,y)<<endl;
        cout<<"The Linear Combination for extended gcd is:"<<a<<"("<<x<<") + "<<b<<"("<<y<<")";
    }
    else
    {
        cout<<"GCD calculation not possible for given numbers!";
    }
    return 0;
}
