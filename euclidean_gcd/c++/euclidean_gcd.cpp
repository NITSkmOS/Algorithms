#include <iostream>

using namespace std;

template<typename T>
T euclidean_gcd(T a,T b){
	while(b != 0){
		T temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}

template<typename T>
T euclidean_gcd_recursive(T a, T b){
	if(a == 0) return b;
	return euclidean_gcd(b % a, a);
}


int main(){
	int a = 10,b = 15;
	cout << euclidean_gcd_recursive(a,b) << endl;
	long x = 21L,y = 49L;
	cout << euclidean_gcd_recursive(x,y) << endl;
	return 0;
}
