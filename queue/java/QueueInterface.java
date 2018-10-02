

public interface QueueInterface<T> {
	/**
	 * Adds a new entry to the back of the queue.
	 * @param newEntry An object to be added.
	 */
	 public void enqueue(T newEntry);
	/**
	 * Removes and returns the entry at the front of the queue.
	 * @return The object at the front of the queue.
	 * @throws NoSuchElementException if the queue is empty before the operation.
	 */
	public T dequeue();
	/**
	 * Retrieves the entry at the front of this queue.
	 * @return The object at the front of the queue.
	 * @throws NoSuchElementException if the queue is empty.
	 */
	public T getFront();
	/**
	 * Detects whether this queue is empty.
	 * @return True is the queue is empty, or false otherwise.
	 */
	public boolean isEmpty();
	/**
	 * removes all entries from this queue.
	 */
	public void clear ();

	

}
