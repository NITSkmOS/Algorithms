class Leaf:
    """
    Class that represent a leaf node of a binary tree.
    """

    def __init__(self, value=None, leftChild=None, rightChild=None):
        self.value = value
        self.leftChild = leftChild
        self.rightChild = rightChild

    def __str__(self):
        return str(self.value)

    def __repr__(self):
        return self.__str__()

    def __del__(self):
        del self.value
        del self.leftChild
        del self.rightChild

    def getChildren(self):
        return [self.leftChild, self.rightChild]


class BST:
    """
    Class that represents a Binary Search Tree.
    <https://en.wikipedia.org/wiki/Binary_search_tree>
    """

    def __init__(self):
        self.root = None

    def __del__(self):
        del self.root

    def find(self, value):
        return self.__findNode(self.root, value)

    def __findNode(self, currentNode, value):
        if currentNode is None:
            raise ValueError("Value not found in BST")
        elif value == currentNode.value:
            return currentNode
        elif value < currentNode.value:
            return self.__findNode(currentNode.leftChild, value)
        else:
            return self.__findNode(currentNode.rightChild, value)

    def insert(self, value):
        self.root = self.__insertNode(self.root, value)

    def __insertNode(self, currentNode, value):
        if currentNode is None:
            return Leaf(value)
        elif value < currentNode.value:
            currentNode.leftChild = self.__insertNode(currentNode.leftChild,
                                                      value)
        elif value > currentNode.value:
            currentNode.rightChild = self.__insertNode(currentNode.rightChild,
                                                       value)
        else:
            currentNode.value = value
        return currentNode


def main():
    values = [1, 2, 0, 1.5, 0.5]
    tree = BST()
    for n in values:
        tree.insert(n)

    print(tree.find(0).rightChild)  # 0.5
    print(tree.root.rightChild)  # 2


if __name__ == '__main__':
    main()
