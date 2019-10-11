#include<stdio.h>
#include<stdlib.h>
struct node
{ int data;
  struct node *left;
  struct node *right;
};
/*struct node* new_node(int d)
{ struct node *new;
  new=(struct node*)malloc(sizeof(struct node));
  new->left=NULL;
  new->right=NULL;
  new->data=d;	
  return(new);
}*/
struct node *create(struct node *root,int k)
{ struct node *new;
  new=(struct node*)malloc(sizeof(struct node));
  new->left=NULL;
  new->right=NULL;
  new->data=k;	
  
   if(root==NULL)
   { root=new;
   }
  
   else if(root->data>k)
    {
	root->left=create(root->left,k);
    }
    else
    { 
	root->right=create(root->right,k);
    }
   

 return(root);
}
void display(struct node *root)
{ if(root!=NULL)
  { printf("%d",root->data);
    display(root->left);
    display(root->right);
  }
}
void main()
{
  struct node *root=NULL;
  root=create(root,1);
  create(root,2);
  create(root,3);
  create(root,4);
  create(root,5);
  create(root,6);
  display(root);
}
