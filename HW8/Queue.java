//package mycollection;
/**
 * The Interface Queue
 *
 * @author Gamze
 * @param <E> the element type
 * extends from Collection Interface
 */

public interface Queue<E> extends Collection<E> {

	/**
	 * Retrieves, but does not remove, the head of this queue. 
	 *
	 * @return head
	 */
	E element();
	/**
	 * Inserts the specified element into this queue
	 *
	 * @param e the element to add
	 */
	void offer(E e);
	/**
	 * Retrieves and removes the head of this queue, or throws if this queue is empty.
	 *
	 * @return head
	 */
	E poll();
}
