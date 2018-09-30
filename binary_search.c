#include<stdio.h>
#define MAX 100
void main()
{
int array[MAX],l,r,mid,n,x,flag=0,i;
printf("enter the no of elements\n");
scanf("%d", &n);
printf("enter the elements of the sorted array\n");
for(i=0;i<n;i++)
{scanf("%d",&array[i]);
}
printf("enter the element to be searched\n");
scanf("%d", &x);
l=0;
r=n-1;
mid=(l+r)/2;
while(l<r)
{if(x==array[mid])
	{printf("\nthe element is at pos %d\n",mid);
	flag=1;
	break;
	}
else if(x<array[mid])
	{r=mid-1;
	mid=(l+r)/2;
	}
else if(x>array[mid])
	{l=mid+1;
	mid=(l+r)/2;
	}

}
if(flag==0)
	printf("The element is not found\n");

}
