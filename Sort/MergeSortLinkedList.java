package com.algo.linkedlist;
import java.util.Random;

public class MergeSortLinkedList {

	public static class Node{
		int data;
		Node next;
		
		public Node(int data) {
			this.data=data;
			this.next=null;
		}
	}

	public static Node addNode(Node head, int data) {
		Node ret;
		if(head==null) {
			return ret=new Node(data);
		} else ret = head;
		while(head.next!=null) {
			head = head.next;
		}
		head.next = new Node(data);
		return ret;
	}
	
	public static void printList(Node head) {
		while(head!=null) {
			System.out.print(head.data+" ");
			head = head.next;
		}
		System.out.println("");
	}
	
	public static Node mergeSortedList(Node head1, Node head2) {
		Node head = null, ret;

		if(head1==null) return head2;
		if(head2==null) return head1;
		
		if(head1.data<head2.data){
			head = head1;
			head1 = head1.next;
		}	
		else{
			head = head2;
			head2 = head2.next;
		}
		ret = head;
		
		while(head1!=null && head2!=null) {
			if(head1.data<head2.data) {
				head.next = head1;
				head = head.next;
				head1 = head1.next;
			} else{
				head.next = head2;
				head= head.next;
				head2 = head2.next;
			}
		}
		
		if(head1!=null)
			head.next=head1;
		if(head2!=null)
			head.next=head2;
		
		return ret;
	}
	
	public static Node mergePartition(Node head) {
		Node head1 = head, head2 = head;
		 
		while(head1!=null && head1.next!=null) {
			head1=head1.next;
			if(head1!=null && head1.next!=null) 
				head1= head1.next;
			else break;
			head2 = head2.next;
		}
		return head2;
	}
	public static Node mergeSort(Node head) {
        if (head == null || head.next == null)
        {
            return head;
        }
 
       Node middle = mergePartition(head);
       Node nextofmiddle = middle.next;
 
        middle.next = null;
 
        Node left = mergeSort(head);
 
        Node right = mergeSort(nextofmiddle);
 
        Node sortedlist = mergeSortedList(left, right);
        return sortedlist;
	}
	public static void main(String[] args) {
		Node head = randomNum(6);

		System.out.println("Given number ");
		printList(head);
		
		head = mergeSort(head);
		System.out.println("After merge sort");
		printList(head);
	}
	
	public static Node randomNum(int n) {
		Node head=null;
		
		Random rand = new Random();
		for(int i=0;i<n;i++) {
			head = addNode(head, rand.nextInt(29));
			//head = addNode(head, (i+1)*rand.nextInt(5));
		}
		return head;
	}
}
