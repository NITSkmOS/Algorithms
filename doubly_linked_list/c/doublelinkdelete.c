#include<stdio.h>
#include<stdlib.h>
struct node
{ int data;
  struct node *next;
  struct node *prev;
};
struct node *head=NULL;
void create(int d)
{ struct node *curr,*t;
  curr=(struct node*)malloc(sizeof(struct node));
  curr->data=d;
  curr->next=NULL;
  curr->prev=NULL;
  if(head==NULL)
  { head=curr;
  }
  else
  { t=head;
    while(t->next!=NULL)
    { t=t->next;
    }
    t->next=curr;
    curr->prev=t;
   }
}
void display()
{ struct node *ptr;
  ptr=head;
  while(ptr!=NULL)
  { printf("%d",ptr->data);
    ptr=ptr->next;
  }
}
void delete(int z)
{ struct node *t1,*t2,*t3;
  t1=head;
  while(t1->data!=z)
  { t1=t1->next;
  }
  t2=t1->next;
  t3=t1->prev;
  t2->prev=t3;
  t3->next=t2;
  free(t1);
}
void delete_beginning()
{ struct node *temp;
  temp=head;
  head=head->next;
  temp->prev=NULL;
  free(temp);
}
void delete_end()
{ struct node *temp,*t;
  t=head;
  while(t->next!=NULL)
  { t=t->next;
  }
  temp=t->prev;
  temp->next=NULL;
  free(t);
}
void main()
{ create(1);
  create(2);
  create(3);
  create(4);
  create(5);
  create(6);
  create(7);
  create(8);
  delete_beginning();
  delete_end();
  delete(4);
  display();
}
