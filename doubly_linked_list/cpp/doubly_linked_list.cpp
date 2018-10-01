#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

//struct defining a doubly linked list
struct Node{
  int data;
  struct Node* prev;
  struct Node* next;
};

struct Node* head;

//GetNewNode returns a new doubly linked list node
struct Node* GetNewNode(int value) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

  newNode->data = value;
  newNode->prev = NULL;
  newNode->next = NULL;

  return newNode;
}

//InsertAtHead inserts a node at the beginning of a doubly linked list
void InsertAtHead(int value) {
  struct Node* newNode = GetNewNode(value);

  if (head == NULL){
    head = newNode;
    return;
  }

  head->prev = newNode;
  newNode->next = head;
  head = newNode;
}

//InsertAtEnd inserts a node at the end of the doubly linked list
void InsertAtEnd(int value) {
    struct Node* newNode = GetNewNode(value);

    if (head == NULL) {
      head = newNode;
      return;
    }

    struct Node* temp = head;

    while(temp->next != NULL) {
      temp = temp->next;
    }

    newNode -> prev = temp;
    temp -> next = newNode;
}

//DeleteNode deletes a node from a doubly linked list
void DeleteNode(int value){
  struct Node* temp = head;

  if(head->data == value){
    head = head->next;
    head->prev = NULL;
    free(temp);
    return;
  }

  while(temp->data != value && temp != NULL) {
    temp = temp->next;
  }
  struct Node* temp2 = temp->next;
  temp->prev->next = temp2;
  temp2->prev = temp->prev;
  free(temp);

}

//display prints the elements of a doubly linked list
void display(){
  struct Node* temp = head;

  while (temp != NULL){
    cout<<temp->data<<" ";
    temp = temp -> next;
  }
}

int main(){
  InsertAtHead(10);
  InsertAtHead(20);
  InsertAtHead(30);
  InsertAtEnd(40);
  display();
  DeleteNode(30);
  DeleteNode(10);
  display();
  return 0;
}
