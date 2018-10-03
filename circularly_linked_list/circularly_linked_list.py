class Node:
	#Define how each entry will be stored
	def __init__(self, data):
		self.data = data
		self.next = None
		self.prev = None

class circular_linked_list:
	def __init__(self):
		self.head = None

	def insert_new_head(self, data, new_node):
		self.head = new_node
		self.head.next = new_node
		self.head.prev = new_node

	def insert_begin(self, data):

		'''
		Places an element at the start of the circularly linked list.

		Simulation:
		(_) _ _ _ _ _ _ 	 _ _ _ _ _ _ _
		    ^		  |		 ^			 |
		    |		  |	==>  |           |
		    |		  |		 |   		 |
		    |----------	     |------------

		'''

		new_node = Node(data)

		if self.head == None:
			self.insert_new_head(data, new_node)

		else:
			new_node.next = self.head.next
			new_node.prev = self.head
			self.head.next = new_node
			self.head.next.prev = new_node


	def insert_end(self, data):

		'''
		Places an element at the end of the circularly linked list.

		Simulation:
		_ _ _ _ _ _ (_)		 _ _ _ _ _ _ _
		^		  |			 ^			 |
		|		  |		==>  |           |
		|		  |		     |   		 |
		|----------			 |------------

		'''


		new_node = Node(data)

		if self.head == None:
			self.insert_new_head(data, new_node)

		else:
			new_node.next = self.head.next
			new_node.prev = self.head
			self.head.next.prev = new_node
			self.head.next = new_node
			self.head = new_node

	def remove_head(self):

		'''
		Removes the head node.

		Simulation:
		_ _ _ _ _ _(_) 		  _ _ _ _ _ _
		^		    |		  ^			|
		|		    |	==>   |         |
		|			|		  |   		|
		|------------	 	  |------------

		'''

		if self.size() == 0:
			return None

		if self.head.next == self.head:
			self.head = None 

		else:
			self.head.prev.next = self.head.next
			self.head.next.prev = self.head.prev
			self.head = self.head.prev

	def display(self):

		'''
		Displays list from the start to the end.

		Simulation:

		1 2 3 4 5 6 7 => Order of output
		_ _ _ _ _ _ _
		^		    |
		|		    |
		|			|
		|------------

		'''

		if self.size() == 0:
			return None

		linear_display = []

		cur_node = self.head.next

		while True:
			linear_display.append(cur_node.data)
			if cur_node == self.head:
				break
			cur_node = cur_node.next

		return linear_display

	def clear(self):

		self.head = None

	def size(self):

		'''
		Returns size of Circularly Linked List.

		Simulation:

		1 2 3 4 5 6(7) => Size
		_ _ _ _ _ _ _
		^		    |
		|		    |
		|			|
		|------------

		'''

		cur_node = self.head
		length = 0

		while True:

			try:
				cur_node = cur_node.next
			except AttributeError:
				break

			length += 1

			if cur_node == self.head:
				break

		return length

def main():
	cll = Circular_Linked_List()
	cll.remove_head()
	print cll.display()
	print cll.size()
	cll.insert_end(15)
	cll.insert_end(10)
	print cll.display()
	print cll.size()
	cll.clear()
	print cll.display()
	print cll.size()

if __name__ == '__main__':
	main()