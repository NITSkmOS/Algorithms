#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
  struct Node *prev;
} Node;

void createList(Node **START) {
  *START = NULL;
  printf("List created successfully\n");
}

void InsertBeg(Node **START, int data) {
  Node *new_node = (Node *)malloc(sizeof(Node));  // Ignore CPPLintBear 
  new_node->data = data;
  new_node->prev = NULL;
  if (*START == NULL) {
    new_node->next = NULL;
    *START = new_node;
  } else {
    (*START)->prev = new_node;
    new_node->next = *START;
    *START = new_node;
  }
}

void InsertEnd(Node **START, int data) {
  Node *new_node = (Node *)malloc(sizeof(Node));  // Ignore CPPLintBear
  new_node->data = data;
  new_node->next = NULL;
  if (*START == NULL) {
    new_node->prev = NULL;
    *START = new_node;
  } else {
    Node *Temp = *START;

    while (Temp->next != NULL)
      Temp = Temp->next;

    Temp->next = new_node;
  }
}

void InsertAfter(Node **START, int data, int target) {
  Node *new_node = (Node *)malloc(sizeof(Node));  // Ignore CPPLintBear
  new_node->data = data;
  if (*START == NULL) {
    new_node->next = NULL;
    new_node->prev = NULL;
    *START = new_node;
  } else {
    Node *Temp = *START;

    while (Temp->data != target && Temp != NULL)
      Temp = Temp->next;

    if (Temp->data != target)
      return;

    new_node->next = Temp->next;
    Temp->next = new_node;
    new_node->prev = Temp;
  }
}

void printList(Node **START) {
  Node *Temp = *START;
  while (Temp != NULL) {
    printf("%d ", Temp->data);
    Temp = Temp->next;
  }
  printf("\n");
  return;
}

int main() {
  Node *START;
  createList(&START);
  InsertBeg(&START, 8);
  InsertBeg(&START, 10);
  InsertBeg(&START, 7);
  printList(&START);
  InsertEnd(&START, 9);
  InsertEnd(&START, 78);
  printList(&START);
  InsertAfter(&START, 45, 9);
  printList(&START);
  return 0;
}
