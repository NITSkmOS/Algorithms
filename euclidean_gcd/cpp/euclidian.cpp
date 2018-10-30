#include <iostream>
using namespace std;

//Calculates GCD of two numbers x,y using the division-based Euclidean Algorithm

int division(int x , int y) {
	while (y != 0) {
		int temp = y;
		y = x % y;
		x = temp;
	}
	return x;
}


//Calculates GCD of two numbers x,y using the recursive-based Euclidean Algorithm

int rec(int x, int y) {
	if (x == 0)
		return y;
	return rec(y % x, x);
}


// Main Method
int main() {
	int a = 20, b = 30;
	cout << "division-based Euclidean Algorithm: " << "a = " << a << "  b = " << b << " result: " << division(a,b) << endl;
	cout << "recursive-based Euclidean Algorithm: " << "a = " << a << "  b = " << b << " result: " <<  rec(a,b) << endl;

	return 0;
}
