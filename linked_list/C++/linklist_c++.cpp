#include <iostream>
#include <cstdio>
using namespace std;
struct node
{
    int data;
    node *next;
};
//Inserting of data in LinkList
node *insert(node *top,int val)
{
    node *ptr = new node;
    ptr->data=val;
    ptr->next=NULL;

    //If LinkList is empty
    if(top==NULL)
    {
        top=ptr;
    }
    else{
            //Insertion in Beginning of LinkList
            ptr->next=top;
            top=ptr;
    }
    return top;
}
//Print LinkList
void display(node *top)
{
    node *ptr=top;
    while(ptr)
    {
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
}
int main()
{
    node *top=NULL;
    //LL : 23->NULL
    top=insert(top,23);
    //LL: 3243->23->NULL
    top=insert(top,3243);
    //LL:213->3243->23->NULL
    top=insert(top,213);
    //Print the LinkList
    display(top);
    return 0;
}
