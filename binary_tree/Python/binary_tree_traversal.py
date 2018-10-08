class Node:
    def __init__(self, key):
        self.left = None
        self.right = None
        self.val = key


def insert(root, node):
    if root is None:
        root = node
    else:
        if root.val < node.val:
            if root.right is None:
                root.right = node
            else:
                insert(root.right, node)
        else:
            if root.left is None:
                root.left = node
            else:
                insert(root.left, node)


def minValueNode(node):
    current = node
    while current.left is not None:
        current = current.left

    return current


def delete(root, node):
    if root is None:
        print("ERROR: No elements in the BST.")
    else:
        if root.val < node:
            delete(root.right, node)
        elif root.val < node:
            delete(root.left, node)
        else:
            if root.right is None:
                temp = root.right
                root = None
                return temp
            elif root.left is None:
                temp = root.left
                root = None
                return temp
            temp = minValueNode(root.left)  # inorder successor
            root.val = temp.val
            root.left = delete(root.left, temp.val)
    return root


# inorder tree traversal
def inorder(root):
    if root:
        inorder(root.left)
        inord.append(root.val)
        inorder(root.right)
    return inord


def preorder(root):
    if root:
        preord.append(root.val)
        preorder(root.left)
        preorder(root.right)
    return preord


def postorder(root):
    if root:
        postorder(root.left)
        postorder(root.right)
        postord.append(root.val)
    return postord


# Let us create the following BST
#      50
#    /    \
#   30     70
#   / \    / \
#  20 40  60 80

inord = []
preord = []
postord = []

r = Node(50)
insert(r, Node(30))
insert(r, Node(20))
insert(r, Node(40))
insert(r, Node(70))
insert(r, Node(60))
insert(r, Node(80))

print("The preorder traversal is :", preorder(r))
print("The inorder traversal is :", inorder(r))
print("The postorder traversal is :", postorder(r))
