import java.util.ArrayList;


public class UnboundQueue {
	//Unbound queue
	private ArrayList<Integer> queueList = null;
	
	public UnboundQueue() {
		queueList = new ArrayList<Integer>();
	}
	
	public boolean isEmpty() {
		return queueList == null ? true : queueList.size() == 0;
	}
	
	
	public void enqueue(int item) {
		System.out.println("Added : " + item);
		queueList.add(item);
	}
	
	
	
	public void dequeue() {
		if( queueList.size() == 0) {
			System.out.println("Queue underflow");
		}else {
			queueList.remove(0);
			System.out.println("Queue size is " + queueList.size());
		}
	}
	
	public void peek() {
		if(queueList.size() == 0) {
			System.out.println("Queue underflow");
		}else {
			System.out.println(queueList.get(0));
		}
	}
	
	
	public static void main(String[] args) {
		UnboundQueue unboundqueue = new UnboundQueue();
		if(unboundqueue.isEmpty()) {
			System.out.println("Empty");
		}
		unboundqueue.enqueue(1); //Added 1
		unboundqueue.enqueue(2); //Added 2
		
		unboundqueue.peek();     
		
		unboundqueue.dequeue();  //remove 1
		
		unboundqueue.peek();
		
		if(!unboundqueue.isEmpty()) {
			System.out.println("Not Empty");
		}
	}
}
