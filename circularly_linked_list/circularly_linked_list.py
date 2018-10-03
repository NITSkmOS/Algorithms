'''
Circularly Linked List which is a linked list in which the
nodes are connected in the form of a circle. There is no NULL at
the end or starting. If we try to go beyond the last element, we
will return to the first node.
'''


class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None


class CircularLinkedList:
    def __init__(self):
        self.head = None

    def insert_new_head(self, new_node):
        self.head = new_node
        self.head.next = new_node
        self.head.prev = new_node

    def insert_begin(self, data):
        '''
        Places an element at the start of the circularly linked list.

        '''

        new_node = Node(data)

        if self.head is None:
            self.insert_new_head(new_node)

        else:
            new_node.next = self.head.next
            new_node.prev = self.head
            self.head.next = new_node
            self.head.next.prev = new_node

    def insert_end(self, data):
        '''
        Places an element at the end of the circularly linked list.
        '''

        new_node = Node(data)

        if self.head is None:
            self.insert_new_head(new_node)

        else:
            new_node.next = self.head.next
            new_node.prev = self.head
            self.head.next.prev = new_node
            self.head.next = new_node
            self.head = new_node

    def remove_head(self):
        '''
        Removes the head node.
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

        print linear_display

    def clear(self):

        self.head = None

    def size(self):
        '''
        Returns size of Circularly Linked List.

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
    cll = CircularLinkedList()
    cll.remove_head()
    cll.display()
    print cll.size()
    cll.insert_end(15)
    cll.insert_end(10)
    cll.display()
    print cll.size()
    cll.clear()
    cll.display()
    print cll.size()


if __name__ == '__main__':
    main()
