#include <iostream>
using namespace std;

//Selection sort Algorithm
void selection_sort(int a[], unsigned dim)
{
	for (int i = 0; i < dim - 1; i++)
	 {
		int min = i;
		for (int j = i + 1; j < dim; j++)
		 {
			if (a[j] < a[min])
				min = j;
		}
		int temp = a[i];
		a[i] = a[min];
		a[min] = temp;
	}
}
// Main Mathod
int main ()
{
	int a[10] ={0,45,8,1,36,4,78,888,-888,100};

	cout << "Representing array BEFORE selection sort: ";
	for (unsigned i = 0; i < 10; i++)
		cout << a[i] << " ";
	cout << endl;

	selection_sort(a,10);

	cout << "Representing array AFTER selection sort: ";
	for (unsigned i = 0; i < 10; i++)
		cout << a[i] << " ";
	cout << endl;
	return 0;
}
