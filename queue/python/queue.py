class Queue:
    def __init__(self):
        self.queue=[]

    def is_empty(self):
        return self.queue==[]

    def enqueue(self, item):
        self.queue.insert(0, item)

    def dequeue(self):
        return self.queue.pop()

    def size(self):
        return len(self.queue)

    def front(self):
        return self.queue[self.size()-1]


def main():
    q = Queue()
    q.enqueue(4)
    q.enqueue('dog')
    q.enqueue(True)
    print("Size of queue is : " + str(q.size()))
    print("Element on front is : " + str(q.front()))
    print(str(q.front()) + " is Deleted ")
    q.dequeue()


if __name__ == '__main__':
    main()
