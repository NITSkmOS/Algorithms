class Queue:
	def __init__(self):
		self.element = []

	def enqueue(self, el):
		self.element.insert(len(self.element), el)

	def dequeue(self):
		return self.element.pop(0)

	def empty(self):
		return self.element == []

	def length(self):
		return len(self.element)

	def end(self):
		return self.element[-1] 

	def front(self):
		return self.element[0]

new_queue = Queue()

# Insert 1, 2, 3 to a queue
new_queue.enqueue(1)
new_queue.enqueue(2)
new_queue.enqueue(3)

# Should return True 
print 'Is empty: ', new_queue.empty()

# Displays element in front of the queue
print 'first element: ', new_queue.front()

# Displays element at the end of the queue
print 'last element: ', new_queue.end()

# Remove each element one by one
new_queue.dequeue()
new_queue.dequeue()
new_queue.dequeue()

# Should return False
# since the queue is already empty
print 'Is empty: ', new_queue.empty()