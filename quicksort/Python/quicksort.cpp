#include<iostream>
using namespace std;
int partition(int arr[],int p,int q){
int k=p;
for(int i=p+1;i<=q;i++){
  if(arr[i]<arr[p]){
    k++;
    int temp=arr[k];
    arr[k]=arr[i];
    arr[i]=temp;
  }
}
int temp=arr[p];
arr[p]=arr[k];
arr[k]=temp;
return k;
  }
void quicksort(int arr[],int p,int q){
  if(p<q){
  int k=partition(arr,p,q);
  quicksort(arr,p,k-1);
  quicksort(arr,k+1,q);
  }
}
int main(){
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
quicksort(arr,0,n-1);
  for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
    return 0;
  }
