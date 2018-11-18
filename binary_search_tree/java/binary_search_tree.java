class binary_search_tree {
//Class defining the node
	class Node {
		int key;
		Node left, right;
		public Node(int item) {
			key = item;
			left = right = null;
		}
	}
	// Root of Binary Search Tree
	Node root;
	// Constructor initiates BST root as null
	binary_search_tree() {
		root = null;
	}
	// This method mainly calls insertNode()
	void insert(int key) {
	root = insertNode(root, key);
	}
	/* A recursive function to insert a new key in BST */
	Node insertNode(Node root, int key) {

		/* If the tree is empty, return a new node */
		if (root == null) {
			root = new Node(key);
			return root;
		}

		/* Otherwise, recursively move down the tree */
		if (key < root.key)
			root.left = insertNode(root.left, key);
		else if (key > root.key)
			root.right = insertNode(root.right, key);

		/* return the (unchanged) node pointer */
		return root;
	}
	// This method mainly calls InorderNode()
	void inorder() {
	inorderNode(root);
	}

	// A utility function to do inorder traversal of BST
	void inorderNode(Node root) {
		if (root != null) {
			inorderNode(root.left);
			System.out.println(root.key);
			inorderNode(root.right);
		}
	}
	// Driver Program to test above functions
	public static void main(String[] args) {
		binary_search_tree tree = new binary_search_tree();
		tree.insert(50);
		tree.insert(30);
		tree.insert(20);
		tree.insert(40);
		tree.insert(70);
		tree.insert(60);
		tree.insert(80);
		// print inorder traversal of the Binary Search Tree
		tree.inorder();
	}
}
