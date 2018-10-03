#include "Stack.h"
#include<assert.h>

template<class T>
Node<T>::Node(T val)
{
	value = val;
	next = 0;
}

template<class T>
Node<T>::~Node()
{
}


template<class T>
void Stack<T>::push(T val)
{
	Node<T>* n = new Node<T>(val);
	if (count == 0)
		head = n;
	else
	{
		n->next = head;
		head = n;
	}
	count++;
}

template<class T>
void Stack<T>::pop()
{
	assert(count != 0);
	Node<T>* temp = head;
	head = head->next;
	delete temp;
	count--;
	
}

template<class T>
T Stack<T>::top()
{
	assert(count != 0);
	return head->value;
}

template<class T>
void Stack<T>::clear()
{
	while (count != 0)
		pop();
}

template<class T>
int Stack<T>::size()
{
	return count;
}

template<class T>
Stack<T>::Stack()
{
}

template<class T>
Stack<T>::~Stack()
{
}

