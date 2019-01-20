//package mycollection;

import java.util.Arrays;
import java.util.Iterator;
import java.util.NoSuchElementException;

// TODO: Auto-generated Javadoc
/**
 * The Class LinkedList.
 *
 * @param <E> the element type
 */
public class LinkedList<E> implements Queue<E> {

	/** The underlying container. */
	private Object[] container;

	/** The real size of this container. */
	private int realSize = 0;

	/** The counter for iterator. */
	private int iteratorCounter = 0;

	/** The Constant DEFAULT_CAPACITY. */
	private static final int DEFAULT_CAPACITY = 10;

	/**
	 * Instantiates a new linked list.
	 */
	public LinkedList() {
		super();
		container = new Object[DEFAULT_CAPACITY];
	}

	/* (non-Javadoc)
	 * @see com.mycollection.Collection#getMyIterator()
	 */
	@Override
	public MyIterator<E> getMyIterator() {
		this.iteratorCounter = 0;
		return new MyIterator<E>(this);
	}

	/* (non-Javadoc)
	 * @see com.mycollection.Collection#add(java.lang.Object)
	 */
	@Override
	public void add(E e) {
		// TODO Auto-generated method stub
		checkingSize();

		this.container[this.realSize++] = e;
	}

	/* (non-Javadoc)
	 * @see com.mycollection.Collection#addAll(com.mycollection.Collection)
	 */
	@Override
	public void addAll(Collection<E> c) {
		for (E e : c) {
			this.add(e);
		}
	}

	/* (non-Javadoc)
	 * @see com.mycollection.Collection#clear()
	 */
	@Override
	public void clear() {
		for (int i = 0; i < this.realSize; i++) {
			this.container[i] = null;
		}
		this.realSize = 0;
	}

	/* (non-Javadoc)
	 * @see com.mycollection.Collection#contains(java.lang.Object)
	 */
	@Override
	public boolean contains(E e) {
		int index = this.findElement(e);

		if (index == -1) {
			return false;
		}

		return true;
	}

	/* (non-Javadoc)
	 * @see com.mycollection.Collection#containAll(com.mycollection.Collection)
	 */
	@Override
	public boolean containAll(Collection<E> c) {
		for (E e : c) {
			if(!this.contains(e)) {
				return false;
			}
		}
		
		return true;
	}

	/* (non-Javadoc)
	 * @see com.mycollection.Collection#isEmpty()
	 */
	@Override
	public boolean isEmpty() {
		return this.realSize == 0;
	}

	/* (non-Javadoc)
	 * @see com.mycollection.Collection#remove(java.lang.Object)
	 */
	@Override
	public void remove(E e) {
		// First we find index of element
		int index = this.findElement(e);

		if (index == -1) {
			throw new ArrayIndexOutOfBoundsException("Array index out of bounds");
		}

		removeAtIndex(index);
	}

	/* (non-Javadoc)
	 * @see com.mycollection.Collection#removeAll(com.mycollection.Collection)
	 */
	@Override
	public void removeAll(Collection<E> c) {

		for (E e : c) {

			int index = this.findElement(e);

			if (index == -1) {
				continue;
			}

			removeAtIndex(index);
		}

	}

	/* (non-Javadoc)
	 * @see com.mycollection.Collection#retainAll(com.mycollection.Collection)
	 */
	@SuppressWarnings("unchecked")
	@Override
	public void retainAll(Collection<E> c) {
		for (int i = 0; i < this.realSize; i++) {

			E value = (E) this.container[i];

			if (!c.contains(value)) {
				// System.out.println("remove element: " + value);
				this.remove(value);
				i--;
			}
		}
	}

	/* (non-Javadoc)
	 * @see com.mycollection.Collection#size()
	 */
	@Override
	public long size() {
		return this.realSize;
	}

	/* (non-Javadoc)
	 * @see java.lang.Iterable#iterator()
	 */
	@Override
	public Iterator<E> iterator() {
		iteratorCounter = 0;
		return this;
	}

	/* (non-Javadoc)
	 * @see java.util.Iterator#hasNext()
	 */
	@Override
	public boolean hasNext() {
		if (this.iteratorCounter < this.realSize) {
			return true;
		}

		return false;
	}

	/* (non-Javadoc)
	 * @see java.util.Iterator#next()
	 */
	@SuppressWarnings("unchecked")
	@Override
	public E next() {
		if (this.iteratorCounter == this.realSize) {
			throw new NoSuchElementException("No such next element");
		}

		return (E) this.container[this.iteratorCounter++];
	}

	/* (non-Javadoc)
	 * @see java.util.Iterator#remove()
	 */
	@Override
	public void remove() {
		this.removeAtIndex(this.iteratorCounter - 1);
	}
	
	/* (non-Javadoc)
	 * @see com.mycollection.Queue#element()
	 */
	@SuppressWarnings("unchecked")
	@Override
	public E element() {
		// TODO Auto-generated method stub
		E value = (E) this.container[0];
		return value;
	}

	/* (non-Javadoc)
	 * @see com.mycollection.Queue#offer(java.lang.Object)
	 */
	@Override
	public void offer(E e) {
		this.add(e);
	}

	/* (non-Javadoc)
	 * @see com.mycollection.Queue#poll()
	 */
	@Override
	public E poll() {
		
		if (this.isEmpty()) {
			throw new RuntimeException("Queue is empty");
		}
		
		E headValue = this.element();
		
		this.remove(headValue);
		
		return headValue;
	}

	/**
	 * This method is used for auto increasing size when when inserting new element to this collection.
	 */
	private void checkingSize() {
		if (this.realSize >= this.container.length) {
			this.container = Arrays.copyOf(this.container, this.realSize * 2);
		}
	}

	/**
	 * Find the specific element.
	 *
	 * @param e the element for finding.
	 * @return the index where the element located in underlying array. Otherwise, -1 is returned
	 */
	@SuppressWarnings("unchecked")
	private int findElement(E e) {
		for (int i = 0; i < this.realSize; i++) {

			E value = (E) this.container[i];

			if (value.equals(e)) {
				return i;
			}
		}
		// can't find element
		return -1;
	}

	/**
	 * Removes the element at specific index.
	 *
	 * @param index the index to be removed.
	 */
	private void removeAtIndex(int index) {

		if (index < this.realSize) {
			this.container[index] = null;
			int tmpIndex = index;

			while (tmpIndex < this.realSize) {
				this.container[tmpIndex] = this.container[tmpIndex + 1];
				this.container[tmpIndex + 1] = null;
				tmpIndex++;
			}

			this.realSize--;
		} else {
			throw new ArrayIndexOutOfBoundsException("Array index out of bounds");
		}
	}
	
	/* (non-Javadoc)
	 * @see java.lang.Object#toString()
	 */
	@SuppressWarnings("unchecked")
	@Override
	public String toString() {		
		String detail = "Size: ";
		detail += Long.toString(this.size());		
		detail += ", [ ";
		
		for (int i = 0; i < this.realSize; i++) {
			E value = (E) this.container[i];
			detail +=value + " ";
		}
		
		detail += "]";
		
		return detail;		
	}

}
