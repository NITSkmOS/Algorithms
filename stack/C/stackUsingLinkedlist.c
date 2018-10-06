/*
Stack implementation using LinkedList

inputFile format:
<number of elements>
<e1> <e2> .. <eN>

Eg. 
5
1 2 3 4 5

*/

#include<stdio.h>
#include<stdlib.h>

#define BUFFER_MAX 256
#define INPUTFILE "inputFile.txt"

typedef struct node
{
  int data;
  struct node *next;
} node;

node *top = NULL;
void push(int input)
{
  if(top == NULL) // Stack empty
  {
    top = (node *) malloc(sizeof(node));
    top->data = input;
    top->next = NULL;
  }
  else
  {
    node *new =(node *) malloc(sizeof(node));
    new->data = input;
    new->next = top;
    top = new;
  }
}

int pop()
{
  if(top == NULL)
  {
    printf("Stack empty.\n");
    exit(1);
  }
  else if(top->next == NULL) // only one element in the queue
  {
    int temp = top->data;
    free(top);
    return(temp);
  }
  else // stack not empty
  {
    int temp = top->data;
    node *tempptr = top;
    top = top->next;
    free(tempptr);
    return(temp);
  }

}

void main()
{
  //node *top = NULL;
  int buffer;
  FILE *fp;
  if((fp = fopen(INPUTFILE, "r")) == NULL)
  {
    perror("Inputfile: ");
    exit(1);
  }
int n;
  fscanf(fp, "%d", &n);

  for(int i = 0; i < n; i++)
  {
    fscanf(fp, "%d", &buffer);
    push(buffer);
  }
  printf("\n");

  for(int i = 0; i < n; i++)
  {
    printf("%d ", pop());
  }
}
