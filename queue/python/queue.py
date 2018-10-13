
class Queue:

    def __init__(self):
        self.queue = list()

    def enqueue(self, data):
        self.queue.insert(0, data)

    def dequeue(self):
        if self.queue.__sizeof__() > 0:
            self.queue.pop()

    def size(self):
        return self.queue.__sizeof__()

    def print(self):
        print(self.queue)


def main():

    q1 = Queue()
    q1.enqueue(4)
    q1.enqueue(21)
    q1.enqueue(7)
    q1.dequeue()
    q1.print()


if __name__ == '__main__':

    main()
