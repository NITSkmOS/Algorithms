#include<stdio.h>

int main()
{
	int arr[5] = { 1, 4, 5, 25, 50};
	int left =0, right=4, mid =0,flag=0;
	int search = 25;
	while(left<right)
	{
		mid = (left+right)/2;
		if(arr[mid]==search)
		{	
			flag=1;
			break;
		}
		else if(arr[mid]>search)
			right = mid-1;
		else
			left = mid+1;
	}
	if(flag==1)
	{
		printf("Element found at index: %d", mid);
	}
	else
		printf("Element not found.");
	return 0;
}
