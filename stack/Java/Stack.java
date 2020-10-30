import java.util.NoSuchElementException;

public class Stack<Item> {
    private int size; // size of the Stack
    private Node first; // top of Stack

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
     * Returns whether the Stack is empty or not.
     *
     * @return true if the Stack is empty, otherwise false.
     */
    public boolean isEmpty() {
        return first == null;
    }

    /**
     * Returns the amount of times in this Stack.
     *
     * @return the amount of times in this Stack.
     */
    public int getSize() {
        return size;
    }

    /**
     * Add an item to this Stack.
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
     * Returns and removes the item on the top of this Stack.
     *
     * @throws NoSuchElementException if this Stack is empty
     */
    public Item pop() throws NoSuchElementException {
        if (isEmpty()) throw new NoSuchElementException("Stack underflow");
        Item item = first.item;
        first = first.next;
        size--;
        return item;
    }


    /**
     * Returns the top item of the Stack, without removing it.
     *
     * @return the item on top of this Stack
     * @throws NoSuchElementException if this Stack is empty
     */
    public Item peek() throws NoSuchElementException {
        if (isEmpty()) throw new NoSuchElementException("Stack underflow");
        return first.item;
    }

    /**
     * Example usage
     */
    public static void main(String[] args) throws NoSuchElementException {
        Stack<String> Stack = new Stack<String>();
        Stack.push("Hello World");
        System.out.println(Stack.peek()); // "Hello World"
        Stack.push("I am on the top now");
        System.out.println(Stack.peek()); // "I am on the top now"
        System.out.println(Stack.pop()); // "I am on the top now"
        System.out.println(Stack.peek()); // "Hello World
    }
}
