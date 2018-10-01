//Implementation of Binary Search in C
//Created By:- Ganesh R. Sanap

#include<stdio.h>

int main(void)
{
  int list[20], n, i, search_num, result;
  printf("Enter the size of the array:");
  scanf("%d", &n);

  printf("Enter the elements in the list in ascending order\n");
  for(i = 0; i < n; i++)
    scanf("%d", &list[i]);

  printf("Enter element to be searched:");
  scanf("%d", &search_num);

  result = binary_search(list, n, search_num);
  // binary_search returns -1 if search_num not found
  if(result == -1) {
    printf("No such element in the list.\n");
    printf("Search unsuccessful :-(\n");
  }
  // binary_search returns the position of the search_num
  // if element found in the list
  else {
    printf("Element found at location %d", result);
    printf("of the list(starting from zero)\n");
  }

  return 0;
}

int binary_search(int arr[], int size, int search_val)
{
  int low, high, mid;
  low = 0;
  high = size - 1;
  while(low <= high) {
    mid = (low + high)/2;
    // if search_val = middle element return mid
    if(search_val == arr[mid])
      return mid;
    // if search_val < middle element search lower/lesser
    // half of the sorted list
    else if(search_val < arr[mid])
      high = mid - 1;
    // if search_val > middle element search higher/greater
    // half of the sorted list
    else if(search_val > arr[mid])
      low = mid + 1;
  }
  return -1;
}
