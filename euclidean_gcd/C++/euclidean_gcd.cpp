#include <iostream>
using namespace std;

int gcd(int a, int b){
	if (a == 0)
		return b;
	return gcd(b % a, a); // returns gcd(remainder, a) if gcd(a,b) = r then gcd(a,b) = gcd(b,r)
}
int main(){
	int a, b;
	cout << "Enter a and b: " << endl;
	cin >> a >> b;
	cout << gcd(a,b);
	return 0;
}