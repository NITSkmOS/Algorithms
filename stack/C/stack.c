#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;

struct node {
	int val;
	Node* next;
};

Node * createNode() {
	Node* node = malloc(sizeof(Node));
	node->val = 0;
	node->next = NULL;

	return node;
}

void stack_push(Node* node, int val) {
	while (node->next != NULL) {
		node = node->next;
	}
	Node* aux = createNode();
	aux->val = val;
	node->next = aux;
}

void stack_pop(Node* node) {
	while (node->next->next != NULL) {
		node = node->next;
	}
	Node* aux = node->next;
	node->next = NULL;
	free(aux);

}

void stack_print(Node* node) {
	while (node->next != NULL) {
		printf("%d\t", node->next->val);
		node = node->next;
	}
	printf("\n");
}

int main( int argc, char ** argv ) {
	Node* node = createNode();

	stack_push(node, 10);
	stack_push(node, 12);
	stack_push(node, 15);
	stack_print(node);
	stack_pop(node);
	stack_print(node);
	return 0;
}