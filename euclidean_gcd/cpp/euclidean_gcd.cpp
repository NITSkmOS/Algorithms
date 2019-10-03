#include <bits/stdc++.h>
using namespace std;

int gcd (int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}
int main() {
  
     int a,b;
     cin >> a >> b;
     cout<<gcd(a,b);
    

    cerr << "Time taken: " << int((clock() * 1000.) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}
