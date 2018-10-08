#include <iostream>

class Node {
	int val;
	Node* next;

public:
	 Node();
	 Node(int val);
	~Node() {}

	 void insert(int val);
	 void remove(int val);
	 void print();
};

Node::Node () {
	this->val = 0;
	this->next = NULL;
}

Node::Node (int val) {
	this->val = val;
	this->next = NULL;
}

void Node::insert(int val) {
	Node* aux = this;
	while (aux->next != NULL) {
		aux = aux->next;
	}

	Node* novo = new Node(val);
	aux->next = novo;
}

void Node::remove(int val) {
	Node* aux = this;
	while (aux->next != NULL) {
		if (aux->next->val == val) {
			Node* rm = aux->next;
			aux->next = rm->next;
			delete(rm);
		}
		aux = aux->next;
	}
}

void Node::print() {
	Node* aux = this;
	while (aux->next != NULL) {
		std::cout << aux->next->val << std::endl;
		aux = aux->next;
	}
}

int main( int argc, char ** argv ) {
	Node node;
	node.insert(10);
	node.insert(20);
	node.insert(30);
	node.insert(100);
	node.insert(55);

	node.print();

	std::cout << std::endl;
	node.remove(100);
	
	node.print();

	return 0;
}