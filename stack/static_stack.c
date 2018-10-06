/* This is a program for the data structure 'Stack' in C language, with a basic array implementation. 

The example such taken is the value of books being inserted into the stack and then being displayed.

Standard functions for push and pop are included.

*/


#include<stdio.h>
#include<stdlib.h>

struct book
{
  int ISBN;
  char name[10];
};

void push(struct book b[10], int *top)
{
  *top=*top +1;
  printf("Enter the name of the book\n");
  scanf("%s", b[*top].name);
  printf("\nEnter the ISBN\n");
  scanf("%d", &b[*top].ISBN);
}

void display(struct book ptr[], int top)
{

int i;
for(i=0; i<=top; i++)
{
  printf("The name of the book is: %s\n ISBN: %d\n", ptr[i].name, ptr[i].ISBN);
}
}


struct book pop(struct book b[10], int *top)
{
  struct book temp;
  temp = b[*top];
  *top=*top-1;
  return temp;
}

int main()
{
  struct book b[10], temp;
  int top = -1;
  int ch;

  for(;;)
  {
    printf("What do you want to do?\n1. Push\n2. Pop.\n3. Display\n");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:
              push(b, &top);
              break;
      case 2:
              if(top==-1)
              {
                printf("Stack Underflow")
              }
              else
              {
                temp = pop(b, &top);
                printf("Name %s\n ISBN %d\n", temp.name, temp.ISBN);
                break;
              }
      case 3:
            display(b, top);
            break;
    }
  }
}
