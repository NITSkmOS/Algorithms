#include <iostream>
#include <vector>
using namespace std;

struct FenwickTree {
	vector<int> v;
	int length;

	FenwickTree(int length) : length(length) {
		v.assign(length + 1, 0);
	}

	void update(int, int);
	int query(int, int);
	int query(int);
};

void FenwickTree::update(int i, int val) {
	while(i <= length) {
		v[i] += val;
		i += i & (-i);
	}
}

int FenwickTree::query(int l, int r) {
	return query(r) - query(l-1);
}

int FenwickTree::query(int i) {
	int ret = 0;
	while(i > 0) {
		ret += v[i];
		i -= i & (-i);
	}
	return ret;
}

int main() {
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	FenwickTree fen(9);
	for(int i = 0 ; i < 9 ; i++) {
		fen.update(i+1, arr[i]);
	}
	printf("%d\n", fen.query(5, 9));
	printf("%d\n", fen.query(5, 5));
	printf("%d\n", fen.query(9));
	
	// update arr[4] to 20
	fen.update(5, -arr[4]);
	arr[4] = 20;
	fen.update(5, arr[4]);
	
	printf("%d\n", fen.query(5, 5));
	printf("%d\n", fen.query(9));
	return 0;
}