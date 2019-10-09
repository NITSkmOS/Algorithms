#include<iostream>
using namespace std;

int getParent(int n)
{
	return n - ( n & -n); 
	
}

int getNext(int n)
{
	return n + (n & -n);
}

int getSum(int a[],int q)
{
	int sum= 0;
	q = q+1;
	while(q > 0)
	{
		sum += a[q];
		q = getParent(q);
	}

	return sum;
}



int main()
{
	int i,n;
	cout<<"Enter value of n"<<endl;
	cin>>n;
	int a[n];
	cout<<"now enter n numbers "<<endl;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}

	
	int tree[n+1]; // this array store the value's of the indexed array ...
	for(i=0;i<n+1;i++)
	{
		tree[i] = 0;
	}

	for(i=0;i<n;i++)
	{
		int p = i+1;
		while(p<n+1)
		{
			tree[p] += a[i] ;
			p = getNext(p);
		}
	}


	cout<<"Indexed Tree is created is .."<<endl;

	for(i=0;i<n+1;i++)
	{
		cout<<tree[i]<<" ";
	}

	cout<<"Now you can play with is ..."<<endl;
	cout<<"Enter the range of sum you want to calculate "<<endl;
	int q ;
	cin>>q;
	cout<<"sum of elements from index 0 to "<<q<<" is :";
	cout<<getSum(tree,q)<<endl;
	return 0;
	
}