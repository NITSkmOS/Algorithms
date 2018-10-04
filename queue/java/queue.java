import java.util.NoSuchElementException;
public class queue<Item>{
    private int size; // size of the Stack
    private Node first;
    private Node last; // top of Stack

    private class Node {
        private Item item;
        private Node next;
    }

    public queue() {
        first = null;
        last = null;
        size = 0;
    }

    public boolean isEmpty() {
        return first == null;
    }

  public int getSize(){
    return size;
  }

  public void enqueue(Item item){
    // Add item to the end of the list.
    Node oldlast = last;
    last = new Node();
    last.item = item;
    last.next = null;
      if (isEmpty()) first = last;
      else oldlast.next = last;
    size++;
  }
  public Item dequeue()throws  NoSuchElementException{
    // Remove item from the beginning of the list.
    if(isEmpty())throw new NoSuchElementException("queue underflow")
    Item item = first.item;
    first = first.next;
    if (isEmpty()) last = null;
    size--;
    return item;
  }
  public static void main(String[] args){
     // Create a queue and enqueue/dequeue strings.
     Queue<String> q = new Queue<String>();
    q.enqueue("I am the first one");
    q.enqueue("I am the second one ");
    q.enqueue("I am the third one ");
    System.out.print(q.dequeue());//I am the first one
    System.out.print(q.dequeue());//I am the second one
    System.out.print(q.dequeue());//I am the third one

}
