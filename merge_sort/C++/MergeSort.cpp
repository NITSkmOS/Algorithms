#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

void Merge(vector<int> &v,int l,int m,int r){
  int n1=m-l+1,n2=r-m ,i,j,k;
  vector<int> L(n1),R(n2);
  for(i=0;i<n1;i++) L[i] = v[i+l];
  for(j=0;j<n2;j++) R[j] = v[m+1+j];
  i=0,j=0,k=l;
  while(i<n1&&j<n2){
    L[i]<=R[j]?(v[k]=L[i],i++):(v[k]=R[j],j++);
    k++;
  }
  while(i<n1){
    v[k]=L[i];
    k++;
    i++;
  }
  while(j<n2){
    v[k]=R[j];
    k++;
    j++;
  }
}

void MergeSort(vector<int> &v,int l,int r){
  if(l<r){
    int m = l + (r-l)/2;
    MergeSort(v,l,m);
    MergeSort(v,m+1,r);
    Merge(v,l,m,r);
  }
}

int main(){
  int n;
  cout<<"Enter number of elements: ";
  vector<int> v(n);
  cout<<"Enter Elements: ";
  for(int i=0;i<n;i++) cin>>v[i];
  MergeSort(v,0,n);
  for(int i=0;i<n;i++) cout<<v[i]<<" ";
}
