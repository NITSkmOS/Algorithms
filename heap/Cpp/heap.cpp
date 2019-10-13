#include<iostream>
using namespace std;

// A heap can be implemented using an array
// The child of parent node ,which is at index i in array
// will always be at index 2i+1 and 2i+2
class heap {
	int arr[50];
	int count;
	public:
		heap();
		bool isFull();
		bool isEmpty();
		void insert(int);
		int getSize(); // Get the current size of heap
		void heapify(int);
		void build_max_heap(); // Build a max heap
		void display_heap(); // Print the elements in the heap
		int delete_first_element(); // Remove the first element and return it
		int get_left_child(int); // Returns the left child of a parent
		int get_right_child(int); // Returns the right child of a parent
		int get_parent(int); // Returns the value of parent index
		int get_max(); // Returns the maximum element in the heap
		void replace(int, int); // Replaces the key value at an index
		void siftUp(int); // To re-convert the changed heap into max heap
};
// Here we assume that the heap can have a maximum size of 50
heap::heap() {
	count = 0;
}

bool heap::isFull() {
	return count == 50;
}

bool heap::isEmpty() {
	return count == 0;
}

void heap::insert(int val) {
	if(!isFull()) {
		arr[count++] = val;
		siftUp(count-1);
	}
}

int heap::getSize() {
	return count+1;
}

// This program demonstrates the logic to build max_heaps
// To build min_heaps simply change the following lines
// Line 54: arr[maxindex] > arr[leftchild]
// Line 62: arr[maxindex] > arr[rightchild]
void heap::heapify(int index) {
	int parent = index;
	int leftchild = 2*index+1;
	int rightchild = 2*index+2;
	int maxindex = parent;
	if(leftchild < count) {
		if(arr[maxindex] < arr[leftchild]) {
			maxindex = leftchild;
		}
	}
	if(rightchild < count) {
		if(arr[maxindex] < arr[rightchild]) {
			maxindex = rightchild;
		}
	}
	if(maxindex != index) {
		int temp = arr[maxindex];
		arr[maxindex] = arr[index];
		arr[index] = temp;
		heapify(maxindex);
	}
}

void heap::build_max_heap() {
	for(int i = count/2; i >= 0; i--) {
		heapify(i);
	}
}

void heap::display_heap() {
	for(int i = 0; i < count; i++) {
		cout << arr[i] << " ";
	}
	cout << "\n";
}

// This also returns the largest element in the heap
int heap::delete_first_element() {
	if(isEmpty()) {
		return -1;
	}
	else {
		int temp = arr[0];
		arr[0] = arr[count-1];
		arr[count-1] = temp;
		heapify(0);
		count--;
		return arr[count];
	}
}

int heap::get_left_child(int i) {
	if(2*i+1 < count) {
		return arr[2*i+1];
	}
	else {
		return -1;
	}
}

int heap::get_right_child(int i) {
	if(2*i+2 < count) {
		return arr[2*i+2];
	}
	else {
		return -1;
	}
}

int heap::get_parent(int i) {
	if(i < count) {
		return arr[i];
	}
	else {
		return -1;
	}
}

int heap::get_max() {
	if(isEmpty()) {
		return -1;
	}
	else {
		return arr[0];
	}
}

void heap::replace(int value, int index) {
	if(index < count) {
		arr[index] = value;
		siftUp(index);
	}
}

void heap::siftUp(int index) {
	while(index != 0) {
		index = (index-1)/2;    // To get the parent of a child
		heapify(index);
	}
}

// Driver method
int main() {
	heap hp;
	hp.insert(4);
	hp.insert(2);
	hp.insert(6);
	hp.insert(7);
	hp.insert(4);
	hp.insert(9);
	hp.insert(1);
	hp.insert(5);
	hp.insert(19);
	hp.insert(5);
	hp.insert(7);
	hp.build_max_heap();
	hp.display_heap();
	cout << hp.delete_first_element() << "\n";
	hp.display_heap();
	cout << hp.get_max() << "\n";
	cout << "Parent"<<hp.get_parent(2) << "\n";
	cout << "Left"<<hp.get_left_child(2) << "\n";
	cout << "Right"<<hp.get_right_child(2) << "\n";
	hp.replace(20, 9);
	hp.display_heap();
}