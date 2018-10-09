
public class QueueClass {


	private double[] queueArray;
	private int arraySize;
	private int front;
	private int rear;
	private int nItems;
	
	public QueueX(int arraySize) {

		this.arraySize = arraySize;
		queueArray = new double[arraySize];
		front = 0;
		rear = -1;
		nItems = 0;


	}

	public void insert(double insert) {

		if(nItems == arraySize) {

			System.out.print("Queue is full!");
		}else {

			if(rear == arraySize -1)
				rear = -1;

			queueArray[++rear] = insert;
			nItems++;


		}


	}

	public double remove() {

		if(nItems == 0) {

			System.out.print("Stack is empty!");
			return -99;

		}else {

			double temp = queueArray[front++];
			if(front == arraySize)
				front = 0;
				nItems--;
				return temp;

		}

	}

	public boolean isFull() {

		if(nItems == arraySize) {

			return true;
		}else
			return false;

	}

	public boolean isEmpty() {


		if(nItems == 0) {

			return true;
		}else
			return false;

	}





}
