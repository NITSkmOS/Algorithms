#include<iostream>
using namespace std;

struct node{
	int data ;
	node *next;
	node *prev;
};

class CircularLinkList
{
	private:
		node *head;
		//node *tail;

	public:
		CircularLinkList(){
			head = NULL;
			//tail = NULL;
		}

		void insert(int data){
			node *newnode = new node();
			newnode->data = data;
			//newnode->next = NULL;
			//newnode->prev = NULL;
			if(head == NULL){
				head = newnode;
				newnode->prev = newnode;
				newnode->next = head;
			}
			else{
				node *p = head;
				node *pr = p->prev;
				newnode->next = p;
				p->prev = newnode;
				head = newnode;
				pr->next = newnode;
				newnode->prev = pr;
			}
		}

		void isCircular(){
			node *p = head;
			node *q = head;
			q = q->next;
			while(p->next != NULL){
				if(p==q){
					cout<<"yes list is circular"<<endl;
					return;
				}
				else{
					p = p->next;
					q = q->next->next;
				}
			}
			cout<<"List is not circular"<<endl;
		}

		void printList()
		{
			node *p = head;
			node *first=p;
			cout<<p->data<<" ";
			p = p->next;
			while(p->next != first)
			{
				cout<<p->data<<" ";
				p = p->next;			
			}
			cout<<p->data<<" "<<endl;
		}
};

int main()
{

	CircularLinkList l;
	l.insert(25);
	l.insert(15);
	l.insert(78);
	l.insert(48);
	l.insert(36);
	l.isCircular();
	l.printList();
}