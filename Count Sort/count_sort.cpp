#include<iostream>
using namespace std;

/* This algorithm is used to sort numbers if 
	the range between which number lies is given ..*/

// whean numbers are repeated and lies in a small range then this algorithm works better and sort the numbers in o(1) time .

void print(int m,int n) // function use to print the number(n) , m times ...
{
	for(int i=0;i<m;i++)
	{
		cout<<n<<" ";
	}
}

int main()
{
	int n,range;
	cout<<"Enter number of elements"<<endl;
	cin>>n;
	cout<<"Enter range of numbers"<<endl;
	cin>>range;
	int i, a[n], r[range];
	for(i=0;i<range;i++) // initilising the array with zero in each position ..
	{
		r[i] = 0;
	}

	cout<<"Enter Numbers now"<<endl;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}

	for(i=0;i<n;i++)
	{
		r[a[i]]++; // it counts the repetation of the numbers at their correponding index
	}

	for(i=0;i<range;i++)
	{
		if(r[i]>0)
		{
			print(r[i],i); // print sorted array..
		}
	}

	return 0;
	
}