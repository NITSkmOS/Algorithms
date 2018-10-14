#include<stdio.h>
#include<stdlib.h>

/*Using variable i to push elements then pop and print the elements. */

int main() {
	void push(int *arr, int *top, int n, int i);
	int pop(int *arr, int *top);
	// number of elements
	int n = 6;
	int arr[n], top = -1;
	// push all elements into the stack
	for(int i = 0; i < n; i++) {
		push(arr, &top, n, i);
	}
	printf("\n");
	// pop elements one by one.
	for(int i = 0; i < n; i++) {
		printf("%d ", pop(arr, &top));
	}
}

void push(int *arr, int *top, int n, int i) {
	if(*top == n) {
		printf("\nStack is full. \n");
	} else {
		arr[++(*top)] = i;
	}
}

int pop(int *arr, int *top) {
	if(*top == -1) {
		printf("\n Stack empty!\n");
		exit(1);
	} else {
		return(arr[(*top)--]);
	}
	return 0;
}
