#include<iostream>
#include "Stack.cpp"
using namespace std;

int main() {
	Stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.pop();
	cout << s.top() << endl;
	cout << s.size()<<endl;
	s.clear();
	cout << s.size()<<endl;
	s.push(15);
	cout << s.top() << endl;
	return 0;
}