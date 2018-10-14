#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
 int data;
 struct node *next;
}node;

node *last=NULL;

void insertbeg(int ele)
{ 
 node *p;
 p=(node*)malloc(sizeof(node));
 p->data=ele;
 if(last==NULL)
 {
  p->next=p;
  last=p;
 }
 else
 {
  p->next=last->next;
  last->next=p;
 }
}

void insertend(int ele)
{ 
 node *p;
 p=(node*)malloc(sizeof(node));
 p->data=ele;
 if(last==NULL)
 {
  p->next=p;
  last=p;
 }
 else
 {
  p->next=last->next;
  last->next=p;
  last=p;
 }
}

void display()
{
 node *q;
 if(last==NULL)
 {
  printf("CLL Empty\n");
  return;
 }
 q=last->next;
 do
 {
  printf("%d", q->data);
  q=q->next;
 }
 while(q!=last->next);
 printf("\n");
}

int deletebeg()
{
 node *p;
 if(last==NULL)
 {
  printf("CLL Empty\n");
  return -1;
 }
 p=last->next;
 if(last->next==last)
  last=NULL;
 else
  last->next=p->next;
 return(p->data);
}

int deleteend()
{
 node *p;
 if(last==NULL)
 {
  printf("CLL Empty\n");
  return -1;
 }
 p=last->next;
 if(last->next==last)
  last=NULL;
 else
 {
  q=last->next;
  while(q->next!=last)
   q=q->next;
  q->next=last->next;
  last=q;
 }
 return(p->data);
}
