
public class Queue {
	
	int rear,maxsize,front;
	String arr[];
	Queue(int n)
	{
		maxsize=n;
		front=-1;
		rear=-1;
		arr=new String[n];
	}
	void enqueue(String n)
	{
		if(front==-1&&rear==-1)
		{
			front++;rear++;
			arr[front++]=n;
		}
		else if(front==maxsize-1)
		{
			System.out.println("Overflow");
		}
		else
		{
			arr[front++]=n;
		}
	}
	void dequeue()
	{
		if(rear==-1)
		{
			System.out.println("Empty Queue");
		}
		else if(rear>front)
		{
			System.out.println("Underflow");
		}
		else
		{
			rear++;
		}
	}
}
