#include <stdio.h>

void swap(int *v, int x, int y)
{
    int aux;

    aux = v[x];
    v[x] = v[y];
    v[y] = aux;
}

void quicksort(int *A, int len) {
    if (len < 2) return;
 
    int pivot = A[len / 2];
 
    int i, j;
    for (i = 0, j = len - 1; ; i++, j--) {
        while (A[i] < pivot) i++;
        while (A[j] > pivot) j--;

        if (i >= j) break;

        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }

    quicksort(A, i);
    quicksort(A + i, len - i);
}

int main(void) {
    int v[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int i;

    for(i = 0; i < 10; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    quicksort(v, 10);
    
    for(i = 0; i < 10; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}
