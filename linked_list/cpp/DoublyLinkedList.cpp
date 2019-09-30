#include<iostream>
using namespace std;

struct node{
	int data;
	node *next;
	node *prev;	
};

class DoublyLinkList
{
	private:
		node *head;
		node *last;
	public:
		DoublyLinkList(){
			head = NULL;
			last = NULL;
		}

		void insert(int data)
		{
			node *newnode = new node();
			newnode->data=data;
			newnode->next = NULL;
			newnode->prev = NULL;
			if(head == NULL){
				head = newnode;
				last = newnode;
			}
			else{
				newnode->prev = last;
				last->next = newnode;
				last = last->next;
			}
		}

		void print(){
			node *p = head;
			while(p->next != NULL){
				cout<<p->data<<" ";
				p = p->next;
			}
			cout<<p->data<<endl;
		}

		void printReverse(){

			node *p = last;
			while(p->prev != NULL){
				cout<<p->data<<" ";
				p = p->prev;
			}
			cout<<p->data<<endl;
		}

		void deleteNode(int data){
			node *p = head;
			node *pr,*nx;
			while(p->data != data && p->next != NULL)
			{
				p = p->next;
			}
			pr = p->prev;
			nx = p->next;
			pr->next = nx;
			nx->prev = pr;
			p->next = NULL;
			p->prev = NULL;
		}

		
};

int main(){

	DoublyLinkList l;
	l.insert(52);
	l.insert(75);
	l.insert(145);
	l.insert(27);
	l.insert(12);
	l.print();
	l.printReverse();
	cout<<"---------"<<endl;
	l.deleteNode(27);
	l.print();
	l.printReverse();
	return 0;
}