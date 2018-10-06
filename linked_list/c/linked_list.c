#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node* link;
}*node;

node getnode(){
	node p=(node*)malloc(sizeof(node));
	p->link=NULL;
	p->data=-99;
	return p;
}

void insertF(int ele, node h){
	if(h->link==h){
		h->link=getnode();
		h->link->data=ele;
		h->link->link=h;
	}
	else{
		node temp=h->link;
		node p=getnode();
		p->data=ele;
		p->link=temp;
		h->link=p;
	}
}

void insertL(int ele, node h){
	if(h->link==h){
		h->link=getnode();
		h->link->data=ele;
		h->link->link=h;
	}
	else{
		node p=h;
		while(p->link!=h)
			p=p->link;
		node l=getnode();
		p->link=l;
		l->data=ele;
		l->link=h;
	}
}

void deleteF(node h){
	if(h->link==h) printf("\nEmpty List\n");
	else{
		node p=h->link;
		if(p->link==h){
			h->link=h;
			printf("Value deleted is \'%d\'\n",p->data);
			free(p);
		}
		else{
			node temp=(h->link)->link;
			printf("Value deleted is \'%d\'\n",(h->link)->data);
			free(h->link);
			h->link=temp;
		}
	}
}

void deleteL(node h){
	if(h->link==h) printf("\nEmpty List\n");
	else{
		node p=h->link;
		if(p->link==h){
			h->link=h;
			printf("Value deleted is \'%d\'\n",p->data);
			free(p);
		}
		else{
			node p=h;
			while(((p->link)->link)!=h) p=p->link;
			printf("Value deleted is \'%d\'\n",(p->link)->data);
			free(p->link);
			p->link=h;
		}
	}
}

void disp(node h){
	node p=h->link;
	if(p==h) printf("List Empty!");
	while(p!=h){		
		printf("%d\t",p->data);
		p=p->link;
	}
	printf("\n");
}
