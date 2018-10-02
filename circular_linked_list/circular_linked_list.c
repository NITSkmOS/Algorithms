#include<iostream>
using namespace std;
struct node
{
    int data;
    node* next;
};
void show(node *head)
{
    node *current=head;
    cout<<"The list is ";
    do
    {
        cout<<current->data<<" ";
        current=current->next;
    }while(current!=head);
    cout<<endl;
}
void insert(node **head,int n)
{
    node *link = new node;
    link->data=n;
    link->next=nullptr;
    if(!*head){
        link->next=link;
        *head=link;
    }
    else
    {
        node *current = *head;
        while(current->next!=*head)
        {
            current=current->next;
        }
        current->next=link;
        link->next=*head;
    }
    show(*head);
}

int main()
{
    node *head=nullptr;
    
    insert(&head,4);
    insert(&head,2);
    insert(&head,8);
    insert(&head,4);
    insert(&head,9);
    insert(&head,1);

    return 0;
}
