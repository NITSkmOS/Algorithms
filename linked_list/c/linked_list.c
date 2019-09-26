#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
};

void createList(Node **START) {
	*START = NULL;
	printf("List created successfully\n");
	return;
}

void insert(struct Node **START, int new_data) {
	struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));	// Ignore CPPLintBear
	new_node->data = new_data;
	new_node->next= (*START);
	*START = new_node;
}

void printList(struct Node *temp) {
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int main() {
	struct Node* START=NULL;
	insert(&START, 12);
	insert(&START, 10);
	insert(&START, 9);
	insert(&START, 56);
	insert(&START, 17);
	printList(START);
}
