#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int val;
	int height;
	struct Node *left, *right;
} Node;

int max(int a, int b) {
	return (a > b) ? a : b;
}

int getHeight(Node* n) {
	if (n == NULL)
		return 0;
	return n->height;
}

Node* newNode(int val) {
	Node* temp = (Node*) malloc(sizeof(Node));	// Ignore CPPLintBear
	temp->val = val;
	temp->left = NULL;
	temp->right = NULL;
	temp->height = 1;
	return temp;
}

int getBalanceFactor(Node* n) {
	if (n == NULL)
		return 0;

	return (getHeight(n->left) - getHeight(n->right));
}

Node* leftRotate(Node* root) {
	Node* newRoot = root->right;
	Node* newRight = newRoot->left;

	newRoot->left = root;
	root->right = newRight;

	newRoot->height = max(getHeight(newRoot->left), getHeight(newRoot->right)) + 1;
	root->height = max(getHeight(root->left), getHeight(root->right)) + 1;

	return newRoot;
}

Node* rightRotate(Node* root) {
	Node* newRoot = root->left;
	Node* newLeft = newRoot->right;

	newRoot->right = root;
	root->left = newLeft;

	newRoot->height = max(getHeight(newRoot->left), getHeight(newRoot->right)) + 1;
	root->height = max(getHeight(root->left), getHeight(root->right)) + 1;

	return newRoot;
}

Node* insertNode(Node* root, int key) {
	if (root == NULL)
		return newNode(key);

	if (key < root->val)
		root->left = insertNode(root->left, key);

	else if (key > root->val)
		root->right = insertNode(root->right, key);

	else
		return root;  // does not re-insert duplicates

	root->height = 1 + max(getHeight(root->left), getHeight(root->right));

	int balance = getBalanceFactor(root);

	// Left Left Case
	if (balance > 1 && key < root->left->val) {
		return rightRotate(root);
	}

	// Right Right Case
	if (balance < -1 && key > root->right->val) {
		return leftRotate(root);
	}

	// Left Right Case
	if (balance > 1 && key > root->left->val) {
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}

	// Right Left Case
	if (balance < -1 && key < root->right->val) {
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}

	return root;
}

Node* minValueNode(Node* root) {
	Node* current = root;
	while (current->left != NULL) current = current->left;
	return current;
}

Node* deleteNode(Node* root, int key) {
	if (root == NULL)
		return root;  // empty tree

	if (key < root->val) {
		root->left = deleteNode(root->left, key);
	} else if (key > root->val) {
		root->right = deleteNode(root->right, key);
	} else {
		// one or no children
		if ( (root->left == NULL) || (root->right == NULL) ) {
			Node* temp = (root->left == NULL) ? root->right : root->left;
			if (temp == NULL) {
				temp = root;
				root = NULL;
			} else {
				*root = *temp;
			}
			free(temp);
		} else {
			// two children
			Node* temp = minValueNode(root->right);
			root->val = temp->val;
			root->right = deleteNode(root->right, temp->val);
		}
	}

	if (root == NULL)
		return root;  // if there was only one node in the tree

	root->height = 1 + max(getHeight(root->left), getHeight(root->right));

	int balance = getBalanceFactor(root);

	// Left Left Case
	if (balance > 1 && getBalanceFactor(root->left) >= 0) {
		return rightRotate(root);
	}
	// Left Right Case
	if (balance > 1 && getBalanceFactor(root->left) < 0) {
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}
	// Right Right Case
	if (balance < -1 && getBalanceFactor(root->right) <= 0) {
		return leftRotate(root);
	}
	// Right Left Case
	if (balance < -1 && getBalanceFactor(root->right) > 0) {
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}

	return root;
}

void printInorderTraversal(Node* root) {
	if (root != NULL) {
		printInorderTraversal(root->left);
		printf("%d ", root->val);
		printInorderTraversal(root->right);
	}
}

void printPreOrderTraversal(Node* root) {
	if (root != NULL) {
		printf("%d ", root->val);
		printPreOrderTraversal(root->left);
		printPreOrderTraversal(root->right);
	}
}

void printPostOrderTraversal(Node* root) {
	if (root != NULL) {
		printPostOrderTraversal(root->left);
		printPostOrderTraversal(root->right);
		printf("%d ", root->val);
	}
}

int main() {
	Node* root = NULL;
	root = insertNode(root, 10);
	root = insertNode(root, 20);
	root = insertNode(root, 30);
	root = insertNode(root, 40);
	root = insertNode(root, 50);

	printf("InOrder: ");
	printInorderTraversal(root);
	printf("\n");

	printf("PreOrder: ");
	printPreOrderTraversal(root);
	printf("\n");

	printf("PostOrder: ");
	printPostOrderTraversal(root);
	printf("\n");

	printf("----------\n");

	root = deleteNode(root, 40);

	printf("InOrder: ");
	printInorderTraversal(root);
	printf("\n");

	printf("PreOrder: ");
	printPreOrderTraversal(root);
	printf("\n");

	printf("PostOrder: ");
	printPostOrderTraversal(root);
	printf("\n");

	return 0;
}
