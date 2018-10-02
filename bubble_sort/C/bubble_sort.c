#include <stdio.h>

void bubble_sort(int[], int);
void print_array(int[], int);
void swap(int*, int*);

int main() {
    int arr[] = {45, 92, 54, 23, 6, 4, 12};
    int n = sizeof(arr) / sizeof(arr[0]);
    bubble_sort(arr, n);
    printf("Sorted array: \n");
    print_array(arr, n);
}

/* Function to swap two numbers */
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* Bubble Sort algorithm */
void bubble_sort(int arr[], int n) {
    int i, j;
    int swapped;
    for (i = 0; i < n - 1; ++i) {
        swapped = 0;
        for (j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
                swapped = 1;
            }
        }

        /* If no two elements are swapped by inner loop, then break */
        if (swapped == 0)
            break;
    }
}

/* Function to print array */
void print_array(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
