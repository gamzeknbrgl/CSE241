#ifndef ITERATOR_H_
#define ITERATOR_H_

#include <vector>
#include <list>
#include <set>
#include <iterator>
#include <algorithm>

namespace myCollection {

	template <typename E, typename C = std::vector<E> >
	class Iterator {

	public:

		Iterator(C& container, const typename C::iterator& it);
		bool hasNext();
		E next() throw(std::runtime_error);
		void remove();

	private:
		C& m_container;
		// use typename here for compiler
		// to recognize C::iterator as a TYPE
		typename C::iterator m_it;

	};	
}

#endif