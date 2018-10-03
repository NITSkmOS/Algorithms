
#include <stdio.h> 
  
// A iterative binary search function. It returns 
// location of x in given array arr[l..r] if present, 
// otherwise -1 
int binarySearch(int arr[], int l, int r, int x) 
{ 
    while (l <= r) 
    { 
        int m = l + (r-l)/2; 
  
        // Check if x is present at mid 
        if (arr[m] == x) 
            return m; 
  
        // If x greater, ignore left half 
        if (arr[m] < x) 
            l = m + 1; 
  
        // If x is smaller, ignore right half 
        else
            r = m - 1; 
    } 
  
    // if we reach here, then element was 
    // not present 
    return -1; 
} 
  
int main(void) 
{ 
    int n;
    scanf("%d",&n);
    int arr[n]; 

    for(int i=0;i<n;i++)
        scanf("%d ",&arr[i]); 
    int x ;
    scanf("%d",&x); 
    int result = binarySearch(arr, 0, n-1, x); 
    (result == -1)? printf("Element is not present"
                                       " in array") 
               : printf("Element is present at "
                                "index %d", result); 
    return 0; 
} 