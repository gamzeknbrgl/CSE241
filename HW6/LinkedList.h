#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include "Collection.h"
#include "List.h"
#include "Queue.h"

namespace myCollection {

	template <typename E, typename C = std::vector<E> >
	class LinkedList : public List<E, C>, public Queue<E, C> {

	public:


		virtual Iterator<E, C> iterator();
		virtual void add(const E& e);
		virtual void addAll(Collection<E, C> &c);
		virtual void clear();
		virtual bool contains(const E& e)const;
		virtual bool containsAll(Collection<E, C> &c)const;
		virtual bool isEmpty() const;
		virtual void remove(const E& e);
		virtual void removeAll(Collection<E, C> &c);
		virtual void retainAll(Collection<E, C> &c);
		virtual size_t size() const;
		virtual E element() const;
		virtual void offer(E e);
		virtual E poll() throw(std::runtime_error);
		// helper functions
		// for working with range-base for loop
		virtual typename C::iterator begin();
		virtual typename C::iterator end();
		// constructors
		LinkedList();
		LinkedList(std::initializer_list<E> elements);

	private:

		C container;

	};

	// partially template specialization for std::set
	// because we dont have an uniform way to insert element
	// when we use std::vector, std::list, std::set as our underlying
	// container, so we need a specialization for our LinkedList
	// to work differently with std::set
	// with std::vector, std::list we call to push_back() for insert element
	// and with std::set we use insert() function

	template <typename E> 
	class LinkedList<E, std::set<E>> : public List<E, std::set<E>>, public Queue<E, std::set<E>> {

	public:
		virtual Iterator<E, std::set<E>> iterator();
		virtual void add(const E& e);
		virtual void addAll(Collection<E, std::set<E>> &c);
		virtual void clear();
		virtual bool contains(const E& e)const;
		virtual bool containsAll(Collection<E, std::set<E>> &c)const;
		virtual bool isEmpty() const;
		virtual void remove(const E& e);
		virtual void removeAll(Collection<E, std::set<E>> &c);
		virtual void retainAll(Collection<E, std::set<E>> &c);
		virtual size_t size() const;
		virtual E element() const;
		virtual void offer(E e);
		virtual E poll() throw(std::runtime_error);
		// helper functions
		// for working with range-base for loop
		virtual typename std::set<E>::iterator begin();
		virtual typename std::set<E>::iterator end();
		// constructors
		LinkedList();
		LinkedList(std::initializer_list<E> elements);

	private:

		std::set<E> container;

	};
	
}

#endif