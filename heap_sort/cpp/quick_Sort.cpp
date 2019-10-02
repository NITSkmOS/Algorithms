 #include<bits/stdc++.h>
using namespace std;
int partition(int *ar,int start,int end)
{
    int pivot=ar[end];   //P indicates the pivot value index

    int P=start;
    int i,t; //t is temporary variable

    //Here we will check if array value is
    //less than pivot
    //then we will place it at left side
    //by swapping

    for(i=start;i<end;i++)
    {
    	if(ar[i]<=pivot)
        {
            t=ar[i];
            ar[i]=ar[P];
            ar[P]=t;
            P++;
        }
     }
     //Now exchanging value of and pivot and P-index
      t=ar[end];
      ar[end]=ar[P];
      ar[P]=t;

      return P; //at last returning the pivot value index
 }
 void quicksort(int *ar,int start,int end)
 {
    if(start<end)
    {
         int P=partition(ar,start,end);
             quicksort(ar,start,P-1);
             quicksort(ar,P+1,end);
    }
}
int main()
{
    int ar[] = {5,19,4,14,8,9};
   int m = sizeof(ar)/sizeof(ar[0]);
      quicksort(ar,0,m-1);
      cout<<"After sorting:\n";
      for(int i=0;i<m;i++)
      {
    	 cout<<ar[i]<<endl;
      }
    return 0;
}
