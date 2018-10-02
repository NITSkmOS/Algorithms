#!/usr/bin/env python3

# Generic tree node class


class TreeNode(object):

    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None
        self.height = 1

# AVL Tree class which supports
# insertion operation


class AVL_Tree(object):

    '''
    Recursive function to insert key in
    subtree rooted with node and returns
    new root of subtree
    '''

    def insert(self, root, key):
        # step 1 : normal BST
        if not root:
            return TreeNode(key)
        elif key < root.val:
            root.left = self.insert(root.left, key)
        else:
            root.right = self.insert(root.right, key)
        # Step 2 : Update the height of the ancestor root
        root.height = 1 + max(self.getHeight(root.left),
                              self.getHeight(root.right))
        # Step 3 : get the balance factor
        balance = self.getBalance(root)
        # step 4 : if root is unbalanced, try the 4 cases
        # case 1 - left left
        if balance > 1 and key < root.left.val:
            return self.rightRotate(root)
        # Case 2 - Right Right
        if balance < -1 and key > root.right.val:
            return self.leftRotate(root)
        # Case 3 - Left Right
        if balance > 1 and key > root.left.val:
            root.left = self.leftRotate(root.left)
            return self.rightRotate(root)
        # Case 4 - Right Left
        if balance < -1 and key < root.right.val:
            root.right = self.rightRotate(root.right)
            return self.leftRotate(root)
        return root

    def leftRotate(self, z):
        y = z.right
        T2 = y.left
        # Perform rotation
        y.left = z
        z.right = T2
        # Update heights
        z.height = 1 + max(self.getHeight(z.left), self.getHeight(z.right))
        y.height = 1 + max(self.getHeight(y.left), self.getHeight(y.right))
        # Return the new root
        return y

    def rightRotate(self, z):
        y = z.left
        T3 = y.right
        # Perform rotation
        y.right = z
        z.left = T3
        # Update heights
        z.height = 1 + max(self.getHeight(z.left), self.getHeight(z.right))
        y.height = 1 + max(self.getHeight(y.left), self.getHeight(y.right))
        # Return the new root
        return y

    def getHeight(self, root):
        if not root:
            return 0
        return root.height

    def getBalance(self, root):
        if not root:
            return 0
        return self.getHeight(root.left) - self.getHeight(root.right)

    def preOrder(self, root):
        if not root:
            return
        print("{0} ".format(root.val), end="")
        self.preOrder(root.left)
        self.preOrder(root.right)

    def inOrder(self, root):
        if not root:
            return
        self.inOrder(root.left)
        print("{0} ".format(root.val), end="")
        self.inOrder(root.right)


def main():
    myTree = AVL_Tree()
    root = None

    root = myTree.insert(root, 10)
    root = myTree.insert(root, 20)
    root = myTree.insert(root, 30)
    root = myTree.insert(root, 40)
    root = myTree.insert(root, 50)
    root = myTree.insert(root, 28)

    print("Pre-order Traversal of the constructed Tree : ")
    myTree.preOrder(root)
    print()
    print("In-order Traversal of the constructed Tree : ")
    myTree.inOrder(root)
    print()


if __name__ == "__main__":
    main()
