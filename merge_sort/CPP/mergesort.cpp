#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll a[1000005];
ll merge(ll a[],ll x[],ll y[],ll l,ll r)
{
	ll i,j,k;
	i=0;
	j=0;
	k=0;
	while(i<l && j<r)
	{
		if(x[i]<=y[j])
			a[k++]=x[i++];
		else
			a[k++]=y[j++];
	}
	while(i<l)
		a[k++]=x[i++];
	while(j<r)
		a[k++]=y[j++];
}
ll mergesort(ll a[],ll n)
{
	if(n<2)
		return 0;
	ll mid = n/2;
	ll x[mid];
	ll y[n-mid];
	ll i,j;
	for(i=0;i<mid;i++)
		x[i]=a[i];
	for(j=0;j<n-mid;j++)
		y[j]=a[i++];
	mergesort(x,mid);
	mergesort(y,n-mid);
	merge(a,x,y,mid,n-mid);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,i;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>a[i];
	mergesort(a,n);
	for(i=0;i<n;i++)
		cout<<a[i]<<' ';
	cout<<endl;
	return 0;
}
