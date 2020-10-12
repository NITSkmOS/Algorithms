#!/bin/env python

class Queue:
	def __init__(self):
		self.items = []

	def isEmpty(self):
		return self.items == []

	def enqueue(self, item):
		self.items.insert(0, item)

	def dequeue(self):
		return self.items.pop()

	def peek(self):
		if not self.isEmpty():
			return self.items[-1]
		else:
			return None

	def size(self):
		return len(self.items)


def main():
	queue = Queue()

	queue.enqueue(1)
	queue.enqueue(2)
	queue.enqueue(3)

	print(f'Front element is: {queue.peek()}')

	x = queue.dequeue()
	queue.enqueue(4)

	print(f'Queue size is {queue.size()}')

	queue.dequeue()
	queue.dequeue()
	queue.dequeue()

	if queue.isEmpty():
		print('Queue Is Empty')
	else:
		print('Queue is Not Empty')


if __name__ == '__main__':
	main()

