#include <iostream>
#include <cstdio>
using namespace std;
struct node
{
    int data;
    node *next;
}*ptr;
node *insert(node * top,int n)
{
    ptr=new node;
    ptr->data=n;
    ptr->next=NULL;

    if(top==NULL)
    {
        top=ptr;
    }
    else{
            ptr->next=top;
              top=ptr;
    }
    return top;
}
void display(node *top)
{
    ptr=top;
    while(ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
}
int main()
{
    node *top=NULL;
    top=insert(top,23);
    top=insert(top,3243);
    top=insert(top,213);
    display(top);
    return 0;
}
