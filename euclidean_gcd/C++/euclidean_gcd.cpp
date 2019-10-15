#include<bits/stdc++.h>
using namespace std;
// Calculates the GCD of two numbers a & b using the division-based Euclidean Algorithm

int GCD(int a,int b)
{
    if(b!=0)
    {
        int temp = b;
        b = a%b;
        a = temp;
    }
    return a;
}

// Calculates the GCD of two numbers a & b using the recursive-based Euclidean Algorithm

int GCD_rec(int a,int b)
{
    if(a==0)
    {
        return b;
    }
    return GCD_rec(b%a,a);
}

// Calculates GCD of two numbers a & b using the Recursive-based Extended Euclidean Algorithm

int GCD_extend(int a,int b,int & x,int & y)
{
     if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    int x1, y1;
    int d = GCD_extend(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

// Main method

int main()
{
    int a = 20, b = 30, x, y;
    cout<<"Division: GCD(a,b) = "<<GCD(a,b)<<endl;
    cout<<"Recursive: GCD(a,b) = "<<GCD_rec(a,b)<<endl;
    cout<<"Extended: GCD(a,b) = "<<GCD_extend(a,b,x,y)<<endl;
    return 0;
}