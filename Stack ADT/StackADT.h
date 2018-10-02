#ifndef StackADT_h
#define StackADT_h

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5 // Size of stack

// Stack Structure
typedef struct
{
  int arr[SIZE];
  int top;
}stack;

void push(stack * , int); // Push operation to insert elements

int pop(stack *); // Pop operation to remove element at top position

void display(stack *); // Display the Entire Stack elements

void peek(stack *); // To show top element without modifying the stack

#endif
