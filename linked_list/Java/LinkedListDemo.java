import java.util.*;
public class LinkedListDemo {
	public static void main(String args[])
	{
		LinkedList<String> ls=new LinkedList<String>();
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		for(int i=0;i<n;i++)
		{
			ls.add(sc.next());
		}
		System.out.println("Linked List:"+ls);
		System.out.println("Enter String to remove:");
		String str=sc.next();
		ls.remove(str);
		System.out.println("Linked List:"+ls);
		System.out.println("Enter Position to remove:");
		int pos=sc.nextInt();
		System.out.println("Linked List:"+ls);
	}
}
