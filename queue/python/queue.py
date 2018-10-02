#!/usr/bin/env python

Queue = {'front': None, 'back': None}


class Node:
    def __init__(self, data, next):
        self.data = data
        self.next = next


def Enqueue(Queue, element):
    N = Node(element, None)
    if Queue['back'] is None:
        Queue['front'] = N
        Queue['back'] = N
    else:
        Queue['back'].next = N
        Queue['back'] = Queue['back'].next


def Dequeue(Queue):
    if Queue['front'] is not None:
        first = Queue['front']
        Queue['front'] = Queue['front'].next
        return first.data
    else:
        if Queue['back'] is not None:
            Queue['back'] = None
        return 'Cannot dequeue because queue is empty'


def main():
    Enqueue(Queue, 'a')
    Enqueue(Queue, 'b')
    Enqueue(Queue, 'c')
    print(Dequeue(Queue))
    print(Dequeue(Queue))
    print(Dequeue(Queue))

if __name__ == "__main__":
    main()
