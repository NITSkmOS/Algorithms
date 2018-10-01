public class Stack<Item>{
    private int size; // size of the stack
    private Node first; // top of stack

    private class Node {
        private Item item;
        private Node next;
    }

    /**
     * Creates an empty Stack instance
     */
    public Stack() {
        first = null;
        size = 0;
    }

    /**
     * Returns whether the stack is empty or not.
     *
     * @return true if the stack is empty, otherwise false.
     */
    public boolean isEmpty() {
        return first == null;
    }

    /**
     * Returns the amount of times in this stack.
     *
     * @return the amount of times in this stack.
     */
    public int getSize() {
        return size;
    }

    /**
     * Add an item to this stack.
     *
     * @param item the item to add.
     */
    public void push(Item item) {
        Node oldFirst = first;
        first = new Node();
        first.item = item;
        first.next = oldFirst;
        size++;
    }

    /**
     * Returns and removes the item on the top of this stack.
     *
     * @throws NoSuchElementException if this stack is empty
     */
    public Item pop() throws  NoSuchElementException{
        if (isEmpty()) throw new NoSuchElementException("Stack underflow");
        Item item = first.item;
        first = first.next;
        size--;
        return item;
    }


    /**
     * Returns the top item of the stack, without removing it.
     *
     * @return the item on top of this stack
     * @throws NoSuchElementException if this stack is empty
     */
    public Item peek() throws  NoSuchElementException{
        if (isEmpty()) throw new NoSuchElementException("Stack underflow");
        return first.item;
    }

    /**
     * Example usage
     */
    public static void main(String[] args) throws NoSuchElementException {
        Stack<String> stack = new Stack<String>();
        stack.push("Hello World");
        System.out.println(stack.peek()); // "Hello World"
        stack.push("I am on the top now");
        System.out.println(stack.peek()); // "I am on the top now"
        System.out.println(stack.pop()); // "I am on the top now"
        System.out.println(stack.peek()); // "Hello World
    }
}
