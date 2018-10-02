#include "StackADT.h"

void push(stack *s, int element)
{
  if(s -> top == SIZE - 1)
  {
    printf("Stack Overflow\n");
  }
  else
  {
    s->arr[++(s->top)] = element;
  }
}

int pop(stack *s)
{
  if(s -> top == -1)
  {
    printf("Stack Undeflow\n");
    return -1;
  }
  else
  {
    return s->arr[(s->top)--];
  }
}

void display(stack *s)
{
  int i;
  if(s -> top == -1)
  {
    printf("Stack is Empty\n");
  }
  else
  {
    for(i = 0; i <= (s->top); i++)
    {
      printf("%d ",s->arr[i]);
    }
    printf("\n");
  }
}

void peek(stack *s)
{
  printf("Element at Top : %d", s->arr[s->top]);
}
