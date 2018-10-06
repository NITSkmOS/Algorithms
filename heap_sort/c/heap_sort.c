#include <stdio.h>

void heapSort(int *array, int size);

int main()
{
    int i, array[10] = { 5, -1, 20, 9, 0, -7, 203, 75, 45, 2};

    heapSort(array, 10);

    for (i = 0 ;  i < 10 ; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}

void heapSort(int *array, int size)
{
    int aux, i, dad, son;
    i = size / 2;

    for (;;)
    {
        if (i > 0)
        {
            i--;
            aux = array[i];
        }
        else
        {
            size--;
            if (size == 0)
            {
                return;
            }
            aux = array[size];
            array[size] = array[0];
        }

        dad = i;
        son = i * 2 + 1;

        while (son < size)
        {
            if ((son + 1 < size) && (array[son+1] > array[son]))
            {
                son++;
            }

            if (array[son] > aux)
            {
                array[dad] = array[son];
                dad = son;
                son = dad * 2 + 1;
            }
            else
            {
                break;
            }
        }

        array[dad] = aux;
    }
}