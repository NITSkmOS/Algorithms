#include<stdio.h>
#include "heap_sort/c/heap.h"
#define MAXN 100

void heapsort(int* v, int len);
int main() {
	//Driver program
	int n;
	scanf("%d", &n);
	int v[MAXN];
	int i;
	for(i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}

	heapsort(v, n);

	for(i = 0; i < n; i++) {
		printf("%d ", v[i]);
	}
	return 0;
}

void heapsort(int* v, int len) {
	MinHeap aux;

	int i;
	for(i = 0; i < len; i++) {
		add(&aux, v[i]);
	}

	for(i = 0; i < len; i++) {
		v[i] = get_value_at_node(&aux, 1);
		rmv(&aux, 1);
	}
}
