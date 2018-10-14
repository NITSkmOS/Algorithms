#!/usr/bin/env python3


class NoSuchNodeException(Exception):
    """Exception class"""
    pass


class Node:
    """
    Class for the structure of node in Linked List

    :param data:    Data value for node
    :param next_node:   Next node reference
    """

    def __init__(self, data=None, next_node=None):
        self.data = data
        self.next_node = next_node

    def compare_to(self, node):
        """
        Method to compare node data

        :return:    Returns True if node data matches
        """
        return node.data == self.data


class LinkedList:
    """
    Class for the Linked List
    :param head:    Reference of the head.
    :param list_size:   List size.
    """

    def __init__(self, head=None, list_size=0):
        self.head = head
        self.list_size = list_size

    def size(self):
        """
        This methods returns the size of the linked list.

        :return:    The size of the linked list.
        """
        return self.list_size

    def is_empty(self):
        """
        This methods determines whether the list is empty.
        :return:    True if the list is empty, otherwise False.
        """
        return self.list_size == 0

    def get_first(self):
        """
        This method returns the first element of the list.

        :return:    The first element of the list.
        """
        if self.is_empty():
            raise NoSuchNodeException()

        return self.head.data

    def getNode(self, i):
        """
        This method takes an index and finds the node residing.

        :raises:    NoSuchNodeException if no such element.
        :param i:   The index of the node.
        :return:    The ith node of the list.
        """
        if i < 0 or i > self.list_size - 1:
            raise NoSuchNodeException()

        current = 0
        p = self.head

        while current < i:
            p = p.next_node
            current += 1

        return p

    def add_first(self, data):
        """
        This method adds a node to the front of the list.

        :param data:    The data of the node to add.
        """
        node = Node(data, self.head)
        self.head = node

        self.list_size += 1

    def add_last(self, data):
        """
        This method adds a node to the back of the list.

        :param data:    The data of the node to add.
        """
        node = Node(data, None)

        if self.is_empty():
            self.head = node
        else:
            tail = self.getNode(self.list_size - 1)
            tail.next_node = node

        self.list_size += 1

    def remove_first(self):
        """
        This method removes the first element of the list.

        :return:    The value of the first element.
        """
        if self.is_empty():
            raise NoSuchNodeException()

        tmp_val = self.head.data
        self.head = self.head.next_node
        self.list_size -= 1
        return tmp_val

    def remove_last(self):
        """
        This method removes the last element of the list.

        :return:    The value of the removed element.
        """
        if self.is_empty():
            raise NoSuchNodeException()

        tail = self.getNode(self.list_size - 1)
        tail_data = tail.data

        if self.list_size == 1:
            self.head = None
        else:
            before_tail = self.getNode(self.list_size - 2)
            before_tail.next_node = None

        self.list_size -= 1
        return tail_data

    def print_list(self):
        """
        Method to print the list in a newline after each element.
        """
        p = self.head
        i = 0

        while i < self.size():
            print(p.data)
            i += 1
            p = p.next_node


def main():
    myList = LinkedList()
    myList.add_first(10)
    myList.add_first(20)
    myList.add_first(30)
    print("Current List after adding 3 elements: ")
    myList.print_list()

    myList.remove_last()
    print("Current List after removing last element: ")
    myList.print_list()


if __name__ == "__main__":
    main()
