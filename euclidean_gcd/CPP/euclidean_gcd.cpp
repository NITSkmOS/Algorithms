#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    return gcd(b % a, a);
}

int main() {
    // a and b are two numbers.
    int a, b;
    cin >> a >> b;

    int ans = gcd(a, b);
    cout << ans;

    return 0;
}
