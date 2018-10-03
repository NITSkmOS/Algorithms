#pragma once

template< class T>
class Node
{
public:
	T value;
	Node<T>* next;

	Node(T);
	~Node();
};

template< class T>
class Stack
{
	Node<T>* head;
	int count;
public:
	void push(T);
	void pop();
	T top();
	void clear();
	int size();
	Stack();
	~Stack();
};


