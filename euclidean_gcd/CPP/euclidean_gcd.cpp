#include <iostream>

int gcd_rec(int a, int b)
{
    return b == 0 ? a : gcd_rec(b, a % b);
}


int gcd_loop(int a , int b) {
	while (b != 0) 
    {
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}


using namespace std;
int main()
{
	int a = 30, b = 40;
    int x, y;

	cout << "Recursive: GCD(" << a << ", " << b << ") = " << gcd_rec(a, b) << endl;
	cout << "Loop     : GCD(" << a << ", " << b << ") = " << gcd_loop(a, b) << endl;

    return 0;
}
