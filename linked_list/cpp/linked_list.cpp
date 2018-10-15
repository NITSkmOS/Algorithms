#include <iostream>

using namespace std;

/*
 * The node structure will hold the data and the address of the next node
 */
struct node {
	int data;
	node *next;
};

/*
 * The list class is the implementation of the singly linked list
 */
class list {
	private:
	node *head, *tail;

	public:
	list();
	void createNode(int value);
	void displayValues();
	void insertAtStart(int value);
	void insertAtPosition(int pos, int value);
	void deleteFirstNode();
	void deleteLastNode();
	void deleteAtPosition(int pos);
};

/*
 * constructor
 */
list::list() {
	head = NULL;
	tail = NULL;
}

/*
 * This method creates a new node and adds it to the end of the list.
 * If the list is empty (head is NULL) then the new node becomes both the head
 * and the tail.
 */
void list::createNode(int value) {
	node *temp = new node;
	temp -> data = value;
	temp -> next = NULL;

	if (head == NULL) {
		head = temp;
		tail = temp;
		temp = NULL;
	} else {
		tail -> next = temp;
		tail = temp;
	}
}

/*
 * Displays the values in the list, seperated by tabs.
 */
void list::displayValues() {
	node *temp = new node;
	temp = head;

	while (temp != NULL) {
		cout << temp -> data << "\t";
		temp = temp -> next;
	}

	cout << "\n";
}

/*
 * Insert a new node at the start of the list
 */
void list::insertAtStart(int value) {
	node *temp = new node;
	temp -> data = value;
	temp -> next = head;
	head = temp;
}

/*
 * Insert a new node at a given position
 */
void list::insertAtPosition(int pos, int value) {
	node *previous = new node;
	node *current = new node;
	node *temp = new node;
	current = head;

	for (int i=1; i < pos; i++) {
		previous = current;
		current = current -> next;
	}

	temp -> data = value;
	previous -> next = temp;
	temp -> next = current;
}

/*
 * Delete the very first node in the list
 */
void list::deleteFirstNode() {
	node *temp = new node;
	temp = head;
	head = head -> next;
	delete temp;
}

/*
 * Delete the last node in the list.
 */
void list::deleteLastNode() {
	node *current = new node;
	node *previous = new node;
	current = head;

	while (current -> next != NULL) {
		previous = current;
		current = current -> next;
	}

	tail = previous;
	previous -> next = NULL;
	delete current;
}

/*
 * Delete a list node at a given position.
 */
void list::deleteAtPosition(int pos) {
	node *current = new node;
	node *previous = new node;
	current = head;

	for (int i=1; i < pos; i++) {
		previous = current;
		current = current -> next;
	}

	previous -> next = current -> next;
}

/*
 * Driver code for testing.
 */
int main() {
	// create a new list;
	list linked_list;

	// add items using createNode
	linked_list.createNode(5);
	linked_list.createNode(10);

	// the linked_list now contains 5, 10
	linked_list.displayValues();

	// insert a value at the beginning of the list
	linked_list.insertAtStart(0);

	// the linked_list now contains 0, 5, 10
	// insert another value
	linked_list.createNode(20);

	// the linked_list now contains 0, 5, 10, 20
	// insert value at position
	linked_list.insertAtPosition(4, 15);

	// the linked_list now contains 0, 5, 10, 15, 20
	// delete the first node
	linked_list.deleteFirstNode();

	// the linked_list now contains 5, 10, 15, 20
	// delete the last node
	linked_list.deleteLastNode();

	// the linked_list now contains 5, 10, 15
	// delete node at position
	linked_list.deleteAtPosition(2);

	// the linked_list now contains 5, 15
	linked_list.displayValues();

	return 0;
}
