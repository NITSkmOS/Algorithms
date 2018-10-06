/*
Simple stack implementation using Array

inputFile format:
<number of elements>
<e1> <e2> .. <eN>

Eg. 
5
1 2 3 4 5

*/

#include<stdio.h>
#include<stdlib.h>

#define INPUTFILE "inputFile.txt"
#define MAX 256

int arr[MAX], n, top = -1;
FILE *fp;

void push()
{
  if(top == n)
  printf("\nStack is full. \n");
  else
  fscanf(fp, "%d", &arr[++top]);
}

int pop()
{
  if(top == -1)
  {
    printf("\n Stack empty!\n");
    exit(1);
}
  else
  return(arr[top--]);
}

void main()
{
  if((fp = fopen(INPUTFILE, "r")) == NULL)
  {
    perror("Inputfile: ");
    exit(1);
  }

  fscanf(fp, "%d", &n);
  if(n > MAX)
  {
    printf("Number of elements, exceeds the limit. \n");
    exit(1);
  }
  for(int i = 0; i < n; i++)
  push();

  printf("\n");

  for(int i = 0; i < n; i++)
  {
    printf("%d ", pop());
  }
}
