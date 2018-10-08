#include <stdio.h>
#include <stdlib.h>

void radixsort(int *array, int size) {
    //função copiada (a partir daqui) de : https://pt.wikipedia.org/wiki/Radix_sort
    int i,*b,max_value,exp = 1;
    max_value = -9999;
    b = (int *)calloc(size, sizeof(int));

	  for (i = 0; i < size; i++) {
        if (array[i] > max_value)
    	    max_value = array[i];
    }
    while (max_value/exp > 0) {
        int bucket[10] = { 0 };
    	for (i = 0; i < size; i++)
    	    bucket[(array[i] / exp) % 10]++; 
    	for (i = 1; i < 10; i++)
    	    bucket[i] += bucket[i - 1];
    	for (i = size - 1; i >= 0; i--)
    	    b[--bucket[(array[i] / exp) % 10]] = array[i];
    	for (i = 0; i < size; i++)
    	    array[i] = b[i];
    	exp *= 10;
    }
    free(b);
    //térmido da cópia da função
}

//Main Function
int main (){
  int * array;
  int size;
  printf("Input the size of array\n");
  scanf("%d",&size);
  array = malloc(sizeof(int)*size);
  printf("Input your array\n");
  for(int i = 0; i < size;i++){
    scanf("%d",&array[i]);
  }
  
  printf("Your array before sorting\n");
  for(int i = 0; i < size;i++){
    printf("%d ",array[i]);
  }
  printf("\n");
  
  radixsort(array,size);
  printf("You array after sorting\n");
  for(int i = 0; i < size;i++){
    printf("%d ",array[i]);
  }
  
  
  
  return 0;
}
