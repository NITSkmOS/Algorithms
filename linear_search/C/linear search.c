#include <stdio.h>
void main()
{
    int a[10], i, item,n,flag=0;
    printf("Enter number of elements : ");
    scanf("%d",&n);
    printf("\nEnter elements of an array:\n");
    for (i=0; i<n; i++)
    {printf("Element : ");
        scanf("%d", &a[i]);}
    printf("\nEnter item to search: ");
    scanf("%d", &item);
    for (i=0; i<n; i++)
       {
        if (item == a[i])
        {   flag=1;
            printf("\nItem found at location %d", i+1);
            break;
        }
       }
    if (flag==0)
        printf("\nItem does not exist.");
    getch();
}
