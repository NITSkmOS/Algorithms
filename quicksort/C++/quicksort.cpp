#include <iostream>
using namespace std;

int part(int input[],int start,int end)
{

	//Setting the pivot	
	int pivot = input[start],i,j,count = 0;
	for(i = start; i <= end;i++)
	{
		if(input[i] < pivot)
		{
			count++;
		}
	}
	input[start] = input[count];
	input[count] = pivot;
	
	//Greater values at right of pivot
	i = start;
	j = end;
	while(i < count && j > count)
	{
		if(input[i] > input[count] && input[j] <= input[count])
		{
			int temp = input[i];
			input[i] = input[j];
			input[j] = temp;
			i++;
			j--;
		}
		else if(input[i] > input[count])
		{
			j--;
		}
		else if(input[i] <= input[count])
		{
			i++;
		}
	}
	return count;	
}
void quicksort(int input[], int size)
{
	if(size == 1 || size == 0)
	{
		return;
	}
	else
	{
		int p = part(input,0,size-1);
		quicksort(input,p);
		quicksort(input+p+1,size-p-1);
	}
}
int main()
{
	int arr[] = {8,4,6,6,5,1,21};
	quicksort(arr,7);
	for(int i = 0; i < 7; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
