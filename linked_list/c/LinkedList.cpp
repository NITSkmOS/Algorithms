#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h>
#include<mem.h>

typedef struct node
{
	int data;
	node *link;
};

void addafter(node**,int);//argument1=root,argument2=value
int number(node*);//argument1=root
int posdel(node**,int);//argument1=root,argument2=position of node
int swap(node**,int,int);//argument1=root,argument2=position 1,argument2=position 2
int reverse(node**,int,int); //argument1=root,argument2=1st position(i.e.1),argument3=end position
void addbeginning(node**,int);//argument1=root,argument2=value
void display(node**);//argument1=root
int sort(node**,char);//argument1=root,argument2='a' for ascending and 'd' for descending
int insert(node**,int,int);//argument1=root,argument2=insert position,argument3=value

void main()
{
	node *root=NULL;
	int n,ch,p,p1;
	char c;
	while(1)
	{
		printf ("\n\nPress 1 to add node(add-after)\nPress 2 to add node(add-beginning)\nPress 3 to know the number of nodes\nPress 4 to delete a particular node\nPress 5 to swap any two nodes\nPress 6 to insert a node\nPress 7 to Reverse the list\nPress 8 to sort in ascending/descending\nPress 9 to display the nodes(/node)\nPress 0 to exit\n\n");
		printf ("\nEnter your choice : ");
		scanf ("%d",&ch);
		switch(ch)
		{
			case 1:	printf ("\nEnter the value to be added : ");
						scanf ("%d",&n);
						addafter(&root,n);
						break;
			case 2:	printf("\nEnter the value to be added: ");
						scanf("%d",&n);
						addbeginning(&root,n);
						break;
			case 3:	printf ("\nThe number of nodes(/node) present : %d",number(root));
						break;
			case 4:	printf ("\nEnter the position of the node to be deleted : ");
						scanf ("%d",&p);
						if (posdel(&root,p)==0)
							printf ("\nNo node has been created yet\n");
						else
							printf ("\nNode has been deleted\n");
						break;
			case 5:  printf ("\nEnter 1st position : ");
						scanf ("%d",&p);
						printf ("\nEnter 2nd position : ");
						scanf ("%d",&p1);
						if (swap(&root,p,p1)==0)
							printf ("\nGiven positions dose not exists\n");
						else
							printf ("\nNodes successfully swaped\n");
						break;
			case 6:	printf ("\nEnter the position(from left) of node after which insertion will take place: ");
						scanf ("%d",&p);
						printf ("\nEnter the value to be inserted : ");
						scanf ("%d",&n);
						if (insert(&root,p,n)==0)
							printf ("\nInvalid Input\n");
						else
							printf ("\nSuccesfully inserted\n");
						break;
			case 7:	if(reverse(&root,1,number(root)) == 0)
							printf ("\nNo node has been created yet\n");
						else
							printf ("\nSuccesfully reversed\n");
						break;
			case 8:	printf("\nEnter 'a' for ascending sort or 'd' for descending sort: ");
						fflush(stdin);
						scanf ("%c",&c);
						p=sort(&root,c);
						if (p==0)
							printf ("\nNo node has been created yet\n");
						else if (p==-1)
							printf ("\nInput Error\n");
						else
							printf ("\nSuccessfully Sorted\n");
						break;
			case 9: 	printf ("\nThe nodes are :- ");
						display(&root);
						break;
			default:	exit(0);
		}
	}
}

void addafter(node**pt,int n)
{
	node *q=(*pt);
	if (*pt == NULL)
	{
		(*pt)=(node*)malloc(sizeof(node));
		(*pt)->link=NULL;
		(*pt)->data=n;
	}
	else
	{
		while(q->link != NULL)
			q=q->link;

		node *temp=(node*)malloc(sizeof(node));
		q->link=temp;
		temp->data=n;
		temp->link=NULL;
	}
	return;
}

int number(node *q)
{
	int c=1;
	if (q==NULL)
		return 0;

	else
	{
		while(q->link != NULL)
		{
			q=q->link;
			c++;
		}
		return c;
	}
}

int posdel(node **pt,int p)
{
	node *q=(*pt);
	int c=1;

	if ((*pt)==NULL)
		return 0;
	else if (p==1)
	{
		(*pt)=(*pt)->link;
		q->link=NULL;
		free(q);
	}
	else
	{
		while(c != (p-1))
		{
			q=q->link;
			c++;
		}
		node *temp=q->link;
		q->link=temp->link;
		temp->link=NULL;
		free(temp);
	}
	return 1;
}

int swap(node **pt,int p,int p1)
{
	node *q=(*pt);
	node *q1=(*pt);
	node *s=(node*)malloc(sizeof(node));
	int c=1,c1=1;
	if((*pt)==NULL)
		return 0;
	else
	{
		while((c != p)&&(q->link != NULL))
		{
			q=q->link;
			c++;
		}
		while ((c1 != p1)&&(q1->link != NULL))
		{
			q1=q1->link;
			c1++;
		}
		if ((c==p)&&(c1==p1))
		{
			s->data=q->data;
			q->data=q1->data;
			q1->data=s->data;
			free(s);
			return 1;
		}
		else
		{
			free(s);
			return 0;
		}
	}
}

/*int reverse(node **pt,int number)
{
	int i=1;
	static int c=1;
	static node *q=(*pt);
	if (number==0)
		return 0;
	if(c==number)
		return 1;
	while(i<=c)
	{
		q=q->link;
		i++;
	}
	addbeginning(pt,q->data);
	posdel(pt,++c);
} */

int reverse(node **pt,int pos1,int pos2)
{
	if (pos2==0)
		return 0;

	if (pos1>=pos2)
		return 1;
	swap(pt,pos1,pos2);
	reverse(pt,++pos1,--pos2);
}

void addbeginning(node **pt,int n)
{
	if (*pt == NULL)
	{
		(*pt)=(node*)malloc(sizeof(node));
		(*pt)->data=n;
		(*pt)->link=NULL;
	}
	else
	{
		node *temp=(node*)malloc(sizeof(node));
		temp->data=n;
		temp->link=(*pt);
		(*pt)=temp;
	}

}

void display(node **pt)
{
	node *q=(*pt);
	if (*pt == NULL)
		printf ("\nNO NODE CREATED YET\n");
	else
	{
		while(q->link != NULL)
		{
			printf (" %d ",q->data);
			q=q->link;
		}
		printf(" %d ",q->data);
		return ;
	}
}

int sort(node **pt,char c)
{
	node *q=(*pt);
	node *s=q->link;
	node *temp=(node*)malloc(sizeof(node));
	if(*pt==NULL)
		return 0;

	int i,j,num=number(*pt);
	if((c=='a')||(c=='A'))
	{
		for(i=1;i<=(num-1);i++)
		{
			for (j=1;j<=num-i;j++)
			{
				if ((q->data)>(s->data))
				{
					temp->data=q->data;
					q->data=s->data;
					s->data=temp->data;
				}
				q=q->link;
				s=s->link;
			}
			q=(*pt);
			s=q->link;
		}
		return 1;
	}
	else if ((c=='d')||(c=='D'))
	{
		for(i=1;i<=(num-1);i++)
		{
			for (j=1;j<=num-i;j++)
			{
				if ((q->data)<(s->data))
				{
					temp->data=q->data;
					q->data=s->data;
					s->data=temp->data;
				}
				q=q->link;
				s=s->link;
			}
			q=(*pt);
			s=q->link;
		}
		return 1;
	}
	else
		return -1;
}

int insert(node **pt,int p,int n)
{
	node *q=(*pt);
	int c=1;
	if((n<=0)&&(n>number(*pt)))
		return 0;
	else
	{
		while(q != NULL)
		{
			if(c==p)
			{
				node *temp=(node*)malloc(sizeof(node));
				temp->link=q->link;
				temp->data=n;
				q->link=temp;
				return 1;
			}
			else
			{
				q=q->link;
				c++;
			}
		}
	}
}
