#include<stdio.h>
#define MAXN 100
#define MAX_NODES 100
typedef struct
{
    int N;
    int heap[MAX_NODES];
} MinHeap;

void add(MinHeap* h, int value);

void rmv(MinHeap* h, int node);

void sift(MinHeap* h, int node);

void percolate(MinHeap* h, int node);

void swap_nodes(MinHeap* h, int node1, int node2);


int get_value_at_node(MinHeap* h, int node);

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
	aux.N = 0;
	int i;
	for(i = 0; i < len; i++) {
		add(&aux, v[i]);
	}

	for(i = 0; i < len; i++) {
		v[i] = get_value_at_node(&aux, 1);
		rmv(&aux, 1);
	}
}

void add(MinHeap* h, int value) {
	h->heap[++(h->N)] = value;

	sift(h, h->N);
	percolate(h, h->N);
}

void rmv(MinHeap* h, int node) {
	swap_nodes(h, node, h->N);
	h->N--;

	sift(h, node);
	percolate(h, node);
}

void sift(MinHeap* h, int node) {
	int son;

	do {
		son = 0;
		if(2*node+1 <= h->N) {
			if (h->heap[2*node+1] < h->heap[2*node]) {
				son = 2*node+1;
			} else {
				son = 2*node;
			}
		} else if (2*node <= h->N) {
			son = 2*node;
		}

		if(h->heap[node] < h->heap[son]) {
			son = 0;
		}

		if(son) {
			swap_nodes(h, node, son);
			node = son;
		}
	} while (son);
}

void percolate(MinHeap* h, int node) {
	while(node > 1 && h->heap[node] < h->heap[node/2]) {
		swap_nodes(h, node, node/2);
		node/=2;
	}
}

void swap_nodes(MinHeap* h, int node1, int node2) {
	int man = h->heap[node1];
	h->heap[node1] = h->heap[node2];
	h->heap[node2] = man;
}

int get_value_at_node(MinHeap* h, int node) {
	return h->heap[node];
}
