//package mycollection;

/**
 * The Class MyIterator is used for getting element from the collection.
 *
 * @param <E> the element type
 */
public class MyIterator<E> {	

	/**
	 * Instantiates a new my iterator.
	 *
	 * @param collection the collection for this iterator to operate.
	 */
	public MyIterator(Collection<E> collection) {
		super();
		this.collection = collection;
	}

	/**
	 * Returns true if the iteration has more elements.
	 *
	 * @return true, if it has next element
	 */
	public boolean hasNext() {
		return this.collection.hasNext();
	}

	/**
	 * Returns the next element in the iteration.
	 *
	 * @return the element
	 */
	public E next() {
		return this.collection.next();
	}

	/**
	 * Removes from the underlying collection the last element returned by this iterator.
	 */
	public void remove() {
		this.collection.remove();
	}

	/** The collection for this iterator to iterate over */
	private Collection<E> collection;
}
