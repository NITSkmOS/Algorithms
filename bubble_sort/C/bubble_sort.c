#include <stdio.h>

void bubble_sort(int arr_size, int *arr)
{
    int swapped = 1;
    while(swapped)
    {
        swapped = 0;
        for(size_t i = 1; i < arr_size; i++)
        {
            if(arr[i-1] > arr[i])
            {
                int prev = arr[i-1];
                arr[i-1] = arr[i];
                arr[i] = prev;
                swapped = 1;
            }
        }
    }
}

int main()
{
    int arr_size = 6, i;
    int arr[6] = {6, 3, 1, 5, 2, 4};
    bubble_sort(arr_size, arr);

    for (i=0; i<arr_size; i++)
    {
        printf("%d\n", arr[i]);
    }
    return 0;
}
