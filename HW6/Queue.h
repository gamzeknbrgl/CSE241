#ifndef QUEUE_H_
#define QUEUE_H_

#include "Collection.h"

namespace myCollection {

	// virtual inheritance for avoiding diamond problem
	// because LinkedList inherit from both List and Queue

	template <typename E, typename C = std::vector<E> >

	class Queue : public virtual Collection<E, C> {

	public:


		virtual Iterator<E, C> iterator() = 0;
		virtual void add(const E& e) = 0;
		virtual void addAll(Collection<E, C> &c) = 0;
		virtual void clear() = 0;
		virtual bool contains(const E& e)const = 0;
		virtual bool containsAll(Collection<E, C> &c)const = 0;
		virtual bool isEmpty() const = 0;
		virtual void remove(const E& e) = 0;
		virtual void removeAll(Collection<E, C> &c) = 0;
		virtual void retainAll(Collection<E, C> &c) = 0;
		virtual size_t size() const = 0;
		virtual E element() const = 0;
		virtual void offer(E e) = 0;
		virtual E poll() = 0;
		// helper functions
		// for working with range-base for loop
		virtual typename C::iterator begin() = 0;
		virtual typename C::iterator end() = 0;		

	};


}




#endif