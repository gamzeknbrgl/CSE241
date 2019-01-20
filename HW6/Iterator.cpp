#include "Iterator.h"
#include <iostream>

namespace myCollection {

	template<typename E, typename C>
	Iterator<E, C>::Iterator(C & container, const typename C::iterator& it)
		: m_container(container), m_it(it) {}

	//Returns true if the iteration has more elements.
	template<typename E, typename C>
	bool Iterator<E, C>::hasNext()
	{
		if (m_it == std::end(m_container)) {
			return false;
		}

		return true;
	}

	//Returns the next element in the iteration and advances the iterator
	template<typename E, typename C>
	E Iterator<E, C>::next() throw(std::runtime_error)
	{
		// for the case when iterator is at the end
		if (m_it == m_container.end()) {
			throw std::runtime_error("iterator out of range");
		}

		++m_it;
		// for the case when iterator is next to the end
		// we increase the iterator so it is now the end
		// throw an exception
 		if (m_it == m_container.end()) {
			throw std::runtime_error("iterator out of range");
		}

		auto nextValue = *m_it;
		return nextValue;
	}
	//Removes from the underlying collection the last element returned by this iterator 
	template<typename E, typename C>
	void Iterator<E, C>::remove()
	{		
		m_it = m_container.erase(m_it);
	}

}