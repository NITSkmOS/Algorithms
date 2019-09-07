#include<iostream>
using namespace std;

void inputarr(int arr[],int n){
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
}
int partition(int arr[],int lb , int ub){
    int pivot=arr[lb];
    int start=lb;
    int endo=ub;
while(start<endo){
    while(arr[start]<=pivot){
        start++;
    }
    while(arr[endo]>pivot){
        endo--;
    }
    if(start<endo){
        swap(arr[start],arr[endo]);
    }
 }
 swap(arr[lb],arr[endo]);
 return endo;
}
void quicksort(int arr[],int lb , int ub){
    if(lb<ub){
        int loc=partition(arr,lb,ub);
        quicksort(arr,lb,loc-1);
        quicksort(arr,loc+1,ub);
    }
}


 void outputarr(int arr[],int n){
   for(int i=0;i<n;i++){
    cout<<arr[i]<<" "<<endl;
   }
 }
 int main(){
   int arr[100],n;
   cout<<"ENTER THE ARRAY ELEMENTS :";
   cin>>n;
   inputarr(arr,n);
   quicksort(arr,0,n-1);
   cout<<"THE SORTED ARRAY IS :"<<endl;
   outputarr(arr,n);

}
