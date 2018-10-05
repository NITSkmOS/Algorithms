#include<stdio.h>
#define max 100000
int main()
{
int i,l,n,a[max],j,k,loc,temp,min;
printf("enter the number of integers in array");
scanf("%d",&n);
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
for(j=0;j<n;j++)
{
 min=a[j];
 loc=j;
 for(k=(j+1);k<n;k++)
 {
  if(min>a[k])
  {
   min=a[k];
   loc=k
  }
 }
  temp=a[j];
  a[j]=a[loc];
  a[loc]=temp;
 }
 for(l=0;l<n;l++)
 printf("%d",a[l]);
 return 0;
 }
