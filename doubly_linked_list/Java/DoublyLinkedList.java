package doubly_linked_list.Java;

import java.util.Comparator;
import java.util.Iterator;
import java.util.NoSuchElementException;

/**
 * Generic iterable doubly linked list of comparable items so they can be sorted.
 * Based in this implementation: http://algs4.cs.princeton.edu/13stacks/DoublyLinkedList.java.html
 * @param <T> Type of object to be put in the list, it must extend comparable to allow elements to be sorted,
 *           otherwise, don't extend comparable.
 */
public class DoublyLinkedList<T extends Comparable<T>> implements Iterable<T>, Comparator<T> {

	/**
	 * First node.
	 */
	private Node<T> first;

	/**
	 * Last node.
	 */
	private Node<T> last;

	/**
	 * List size.
	 */
	private int size;

    /**
     * Comparator to allow sorting this list.
     */
	private Comparator<T> comp;

	/**
	 * Creates an emtpty list.
	 */
	public DoublyLinkedList(){
		first = null;
		last = null;
		size = 0;
		comp = new listComparator<>();
	}

    /**
     * Comparator for list elements
     * @param <T> type of elements in the list
     */
	private class listComparator<T extends Comparable<T>> implements Comparator<T>{
		@Override
		public int compare(T comparable, T comparable2) {
			return comparable.compareTo(comparable2);
		}
	}

	/**
	 * Returns the list size.
	 * @return list size.
	 */
	public int getSize() {
		return size;
	}

	/**
	 * Returns true if the list is empty, otherwise it returns false.
	 * @return true if the list is empty, otherwise it returns false.
	 */
	public boolean isEmpty() {
		return size == 0;
	}

	/**
	 * Returns the list's first element.
	 * @return the list's first element.
	 */
	public T getFirst(){
		return first.data;
	}

	/**
	 * Returns the list's last element.
	 * @return the list's last element.
	 */
	public T getLast(){
		return last.data;
	}


	/**
	 * Adds an element in the last position of the list
	 * @param pToAdd element to be added
	 */
	public void addAtEnd(T pToAdd) {
		insertAfter(last, pToAdd);
	}

	/**
	 * Adds an element to the beginning of the list.
	 * @param pToAdd Element to be added
	 */
	public void addAtBeginning( T pToAdd ){
		Node<T> toAdd = new Node<>();
		toAdd.data = pToAdd;

		if( isEmpty()){
			first = toAdd;
			last = toAdd;
		}
		else{
			first.previous = toAdd;
			toAdd.next = first;
			first = toAdd;
		}
	}

	/**
	 * Inserts an element after any list node
	 * @param pPrevious Node that will precede the new element.
	 * @param pToAdd Element to be added to the list
	 */
	private void insertAfter( Node<T> pPrevious, T pToAdd ){
		Node<T> toAdd = new Node<>();
		toAdd.data = pToAdd;

		if( isEmpty()){
			first = toAdd;
			last = toAdd;
		}
		else if( last == pPrevious ){
			pPrevious.next = toAdd;
			toAdd.previous = pPrevious;
			last = toAdd;
		}
		else{
			toAdd.next = pPrevious.next;
			toAdd.previous = pPrevious;
			pPrevious.next.previous = toAdd;
			pPrevious.next = toAdd;
		}
		size++;
	}

	/**
	 * Adds a new element in a given index
	 * @param pToAdd Element to be added
	 * @param pIndex Index where the element is going to be added
	 */
	public void addAtK(T pToAdd, int pIndex) {
		if( pIndex < size ){
			if( pIndex == 0){
				addAtBeginning(pToAdd);
			}
			else
				insertAfter(getNode(pIndex), pToAdd);
		}
		else if( pIndex == size)
			addAtEnd(pToAdd);
		else
			throw new NoSuchElementException( "The index doesn't exist" );
	}

	/**
	 * Replaces the element in the given index with the new element.
	 * @param pToAdd New element.
	 * @param pIndex Index of the element to be replaced.
	 */
	public void replace( T pToAdd, int pIndex ){
		Node<T> current = null;
		if( !isEmpty()){
			current = first;
			for( int i = 0; i < pIndex; i++){
				current = current.next;
			}
			current.data = pToAdd;
		}
		else{
			addAtEnd(pToAdd);
		}
	}


	/**
	 * Returns the element in the given index
	 * Based in the algorithm in the book "A practical guide to data structures and algorithms using Java"
	 * @param pIndex Element index.
	 * @return Element in the given index.
	 */
	public T getElement(int pIndex) {
		Node<T> current = null;
		if( !isEmpty() && pIndex < size && pIndex >= 0){
			current = first;
			for( int i = 0; i < pIndex; i++){
				current = current.next;
			}
			return current.data;
		}
		return null;
	}

	/**
	 * Returns the node in the given index.
	 * @param pIndex index of the node.
	 * @return Node in the given index.
	 */
	private Node<T> getNode(int pIndex) {
		Node<T> current = null;
		if( !isEmpty() && pIndex < size && pIndex >= 0){
			current = first;
			for( int i = 0; i < pIndex; i++){
				current = current.next;
			}
			return current;
		}
		return null;
	}

	/**
	 * Deletes a node from the list.
	 * @param pNode Deletes the node in the given index.
	 */
	private void delete( T pNode ) {
		int position = positionOf( pNode );
		Node<T> toDelete = getNode( position );
		if( toDelete == null ){
			throw new NoSuchElementException( "El nodo no existe." );
		}
		else if( toDelete == first ){
			Node<T> next = getNode( positionOf ( toDelete.data ) + 1 );
			next.previous = null;
			first = next;
			toDelete.next = null;
		}
		else if( toDelete == last ){
			Node<T> previous = getNode( positionOf ( toDelete.data ) - 1 );
			previous.next = null;
			last = previous;
			toDelete.previous = null;
		}
		else{
			Node<T> next = getNode(positionOf(toDelete.data) + 1 );
			Node<T> previous = getNode(positionOf(toDelete.data) - 1 );
			previous.next = next;
			next.previous = previous;
			toDelete.next = null;
			toDelete.previous = null;
		}
		size--;
	}

	/**
	 * Deletes an element in the given index.
     * @param pIndex Index of the element to be deleted.
	 */
	public void deleteAtK(int pIndex) {
		delete(getElement(pIndex));
	}

	/**
	 * Returns the position of the given element
	 * Based in an algorithm from the book "A practical guide to algorithms and data structures using java"
	 * @return Position of the given element.
	 */
	public int positionOf(T pData) {
		Node<T> current;
		Integer pos;
		for( pos = 0, current = first; pos < size; pos++, current = current.next)
			if( current.data.equals(pData) )
				return pos;

		throw new NoSuchElementException();
	}

    /**
     * Indicates if the given element is in the list.
     * @param pElement Element to be searched in the list
     * @return true if the element is in the list, otherwise returns false
     */
	public boolean contains( T pElement ){
		for( T element : this ){
			if( element.equals(pElement))
				return true;
		}
		return false;
	}

    /**
     * Returns an array with the list elements.
     * @return array with the list elements.
     */
	public Comparable<T>[] toArray(){
		Comparable<T>[] ans = new Comparable[size];
		int i = 0;
		for( T element : this){
			ans[i] = element;
			i++;
		}
		return ans;
	}

	/**
	 * Returns the list iterator.
	 */
	@Override
	public Iterator<T> iterator() {
		return new DLLIterator();
	} 

	/**
	 * Nodes that contain the list elements.
	 * @param <T> Type of element that the node will contain.
	 */
	private class Node<T>{

		/**
		 * Data held by the node.
		 */
		private T data;

		/**
		 * Pointer to the next node.
		 */
		private Node<T> next;

		/**
		 * Pointer to the previous node.
		 */
		private Node<T> previous;

		/**
		 * Returns the data
		 */
		public String toString(){
			return data + ", ";
		}
	}

	/**
	 * List iterator.
	 */
	private class DLLIterator implements Iterator<T>{
		/**
		 * Current element that the iterator is iterating.
		 * It is initialized in the first element.
		 */
		private Node<T> current = first;

		/**
		 * Last element that the iterator accessed.
		 */
		private Node<T> lastAccessed;

		/**
		 * Index of the element that the iterator is accessing.
		 */
		private int index = 0;


		/**
         * Indicates if there's an element after the current element.
		 * @return true if there's an element after the current element, false otherwise.
		 */
		@Override
		public boolean hasNext() {
			return current != null;
		}

		/**
         * Returns the element after the current one, if it exists.
		 * @return the element after the current one, if it exists.
		 */
		@Override
		public T next() {
			if( !hasNext())
				throw new NoSuchElementException();
			else{
				lastAccessed = current;
				T item = current.data;
				current = current.next;
				index++;
				return item;
			}
		}
	}

    /**
     * As T extends Comparable, the iterator must implement compare() as well
     * @param o1 first object to compare
     * @param o2 second object to compare
     * @return a positive int if the first element is bigger than the second, a negative number if the second element is
     * bigger or 0 if they are equal.
     */
	@Override
	public int compare(T o1, T o2) {
		return o1.compareTo(o2);
	}
}
