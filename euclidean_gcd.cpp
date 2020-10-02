#include <bits/stdc++.h>
using namespace std;

int iterativeGCD(int a, int b){
  int c = a + b;
    while(c > 0){
        if(a % c == 0 && b % c == 0)
          return c;
        c--;
    }
    return 1;
}

int recursiveGCD(int a, int b){
    if(b == 0) return a;
    return recursiveGCD(b, a%b);
}

int main(){
    int a, b;
    cin >> a >> b;

    cout << iterativeGCD(a,b) << '\n';
    cout << recursiveGCD(a,b) << '\n';

    return 0;
}
