//package mycollection;

//import mycollection.MyIterator;


/**
 * The Interface Collection.
 *
 * @author Gamze
 * @param <E> the element type
 */
public interface Collection<E> extends Iterable<E>, java.util.Iterator<E>  {

	/**
	 * Gets the custom iterator.
	 *
	 * @return the my iterator
	 */
	public MyIterator<E> getMyIterator();

	/**
	 * Adds the element.
	 *
	 * @param e the element to add
	 */
	void add(E e);

	/**
	 * Adds the all the elements.
	 *
	 * @param c the collection to add.
	 */
	void addAll(Collection<E> c);

	/**
	 * Clear all the element of this collection.
	 */
	void clear();

	/**
	 * Check if the element is in this container.
	 *
	 * @param e the element to check.
	 * @return true, if element is in the container, otherwise false
	 */
	boolean contains(E e);

	/**
	 * Check if this collection contains other collection.
	 *
	 * @param c the collection for checking.
	 * @return true, if this collection contains other collection.
	 */
	boolean containAll(Collection<E> c);

	/**
	 * Checks if this collection is empty.
	 *
	 * @return true, if this collection is empty.
	 */
	boolean isEmpty();

	/**
	 * Removes the element from this collection.
	 *
	 * @param e the element to be removed.
	 */
	void remove(E e);

	/**
	 * Removes all common element between this collection and the other.
	 *
	 * @param c the collection which contain element to be removed
	 */
	void removeAll(Collection<E> c);

	/**
	 * Retain all matching elements in this collection that match all elements from the other collection passed as parameter.
	 *
	 * @param c the collection used to retain.
	 */
	void retainAll(Collection<E> c);

	/**
	 * Size of this collection.
	 *
	 * @return the size of this collection in long
	 */
	long size();
}
