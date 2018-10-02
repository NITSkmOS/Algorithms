#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    return gcd(b % a, a);
}

int main()
{
    // a and b are two numbers.
    ll a, b;
    cin >> a >> b;

    ll ans = gcd(a, b);
    cout << ans;

    return 0;
}