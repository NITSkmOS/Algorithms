class Stack:
    """
    Class for operations related to stack.
    """

    def __init__(self):

        self.stack = []  # Initialise empty stack

    def push(self, dataval):
        """
        Method to push items in stack.

        :param dataval: Value that user needs to push.
        """

        self.stack.append(dataval)

    def pop(self):
        """
        Method for removing the last element from the stack.

        :return:   Element that is popped.
        """

        if len(self.stack) <= 0:
            raise IndexError("No element in the Stack")

        else:
            return self.stack.pop()

    def top(self):
        """
        Method to show the last element of the stack.

        :return:    last element of the stack.
        """

        return self.stack[len(self.stack)-1]

    def display(self):
        """
        Method to print all elements of the stack.
        """

        print(*self.stack)


def main():
    AStack = Stack()
    AStack.push("Mon")
    AStack.push("Tue")
    AStack.pop()
    AStack.push("Wed")
    m = AStack.top()
    print(m)
    AStack.push("Thu")
    AStack.display()


if __name__ == "__main__":
    main()
