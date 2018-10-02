#include "StackADT.h"

int main()
{
  int choice,element;
  stack s;
  s.top = -1;
  while(1)
  {
    system("cls")
    display(&s);
    printf("1. Push\n 2. Pop\n 3. Display Stack \n 4. Peek/(Element at Top/) \n 5. EXIT \n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    switch(choice)
    {
      case 1:
        printf("Enter element to be added: ");
        scanf("%d", &element);
        push(&s, element);
        break;
      case 2:
        pop(&s);
        break;
      case 3:
        display(&s);
        break;
      case 4:
        peek(&s);
        break;
      case 5:
        exit(0);
      default:
        printf("Invalid Choice.\n");
    }
  }
  return 0;
}
