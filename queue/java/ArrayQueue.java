

import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.NoSuchElementException;
import java.util.Scanner;

;

public final  class ArrayQueue<T> implements QueueInterface<T> {
	private T[] queue;
	private int sizeOfQueue;
	private int firstIndex;
	private int lastIndex;
	private boolean initialized = false;
	private static final int DEFAULT_CAPACITY=2;
	private static final int MAX_CAPACITY=10000;
	
	
	public ArrayQueue() {
		this(DEFAULT_CAPACITY);
	}
	public ArrayQueue(int initialCapacity) {
		checkCapacity(initialCapacity);
		
		@SuppressWarnings("unchecked")
		T[] tempQueue= (T[])new Object[initialCapacity];
		queue=tempQueue;
		lastIndex=0;
		sizeOfQueue = lastIndex;
		firstIndex=0;
		initialized = true;
			
	}
	
	/**
	 * @throws SecurityException if not initialized.
	 */
	private void checkInitialization()
    {
        if (!initialized)
        {
            throw new SecurityException ("Queue doesn't exist.");
        }
    }
   
	/**
	 * @throws IllegalStateException if new array length is bigger than MAX_CAPACITY
	 * @param newLength to be checked
	 */
	private void checkCapacity(int newLength) {
		if (newLength > MAX_CAPACITY) {
			throw new IllegalStateException("Maximum capacity of queue "+
											"is exceeded.");
		}
		
	}
	
	/**
	 * Extend the Array when it gets full
	 * @throws IllegalArgumentException if input is not 2 or 3.
	 */
	private void ensureCapacity() {
		if(lastIndex == queue.length -1) {
			@SuppressWarnings("resource") 
			Scanner scanner = new Scanner(System.in);
			System.out.println("Please enter 2 or 3 to enlarge your queue:");
			int number= scanner.nextInt();
			try{
			if (!(number == 2 || number == 3)) {
				throw new IllegalArgumentException("The number you entered " +
													"wasn't 2 or 3.");
			}
			
			int newLength=queue.length*number;
			checkCapacity(newLength);
			queue = Arrays.copyOf(queue,newLength);
			}catch(InputMismatchException e) {
				System.out.println("Please enter a valid number of type integer: "
						  + e.getMessage());
		}
		
		}
	}

	
	@Override
	public void enqueue(T element) {
		checkInitialization();
		ensureCapacity();
		
		queue[lastIndex]=element;
		lastIndex++;
			sizeOfQueue++;
	}

	@Override
	public T dequeue() {
		checkInitialization();
		
		T result;
		if (isEmpty()) {
			throw new NoSuchElementException("Queue is empty.");
		}
		else {
			result= queue[firstIndex];
			for (int i=0;i<sizeOfQueue;i++) {
				queue[i]=queue[i+1];	
			}
			lastIndex--;
			sizeOfQueue--;	
		}	
		return result;
	}

	@Override
	public T getFront()  {
		checkInitialization();
		T result;
		if(isEmpty()) {
			throw new NoSuchElementException("Queue is empty.");
		}
		result=queue[firstIndex];
		return result;
	}

	@Override
	public boolean isEmpty() {
		return sizeOfQueue==0;
	}

	@Override
	public void clear() {
		checkInitialization();
		
		for (int i =firstIndex;i<sizeOfQueue;i++){
			if(queue[i]!=null) {
				dequeue();
				
			}
		}
		lastIndex=0;
		sizeOfQueue=0;
	}
	



}



