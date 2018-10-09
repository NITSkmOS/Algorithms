

public class MainClass {

	public static void main(String[] args) {


		//Queue class object and initialization
		QueueX q = new QueueX(5);


		//While the queue is not full, add values to the queue
		while(!q.isFull()) {

			q.insert(10);
			q.insert(20);
			q.insert(30);
			q.insert(40);
			q.insert(50);

		}


		//while queue is not empty, print out the values in the queue
		while(!q.isEmpty()) {

			double result = q.remove();
			System.out.print(result + " ");

		}

	}

}
