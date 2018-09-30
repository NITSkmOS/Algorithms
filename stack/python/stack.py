class Stack:
    """
    Class for operations related to stack.
    """

    def __init__(self):
        """
        Constructor.
        """
        self.stack = []    # Initialise empty list

    def push(self, dataval):
        """
        Method to push items in stack.

        dataval: Value that user needs to push.
        """
        self.stack.append(dataval)    # Add dataval at the end of the list.

    def pop(self):
        """
        Method for removing the last element from the stack.

        Returns
        -------
        element that is popped.
        """
        if len(self.stack) <= 0:
            # Raise an error is if stack is empty.
            return ("No element in the Stack")
        else:
            return self.stack.pop()

    def top(self):
        # Show the last element of the list.
        return self.stack[len(self.stack)-1]

    def display(self):
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
