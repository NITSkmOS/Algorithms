#include <stdio.h>
#include <stdlib.h>

//Counting Sort
int * counting_sort(int * array, int size){

  int max_value = -9999;
  int * arr_aux;
  int j = 0;

  //Taking the major number on the array
  for(int i = 0; i < size;i++){
    if(array[i] > max_value){
      max_value = array[i];
    }
  }
  arr_aux = malloc((sizeof(int)*max_value)+1);

  //Resetting the array
  for(int i = 0; i < max_value+1;i++){
    arr_aux[i] = 0;
  }

  //Counting the elements
  for(int i = 0; i < size;i++){
    arr_aux[array[i]]++;
  }
  //Sorting the array
  for(int i = 0; i < max_value+1;i++){
    while(arr_aux[i] != 0){
      array[j] = i;
      j++;
      arr_aux[i]--;
    }
  }
  return array;
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

  array = counting_sort(array,size);
  printf("You array after sorting\n");
  for(int i = 0; i < size;i++){
    printf("%d ",array[i]);
  }



  return 0;
}
