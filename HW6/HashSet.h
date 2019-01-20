#ifndef HASHSET_H_
#define HASHSET_H_

#include "Collection.h"
#include "Set.h"

namespace myCollection {

	template <typename E, typename C = std::vector<E> >
	class HashSet : public Set<E, C> {

	public:

		virtual Iterator<E, C> iterator();
		virtual void add(const E& e);
		virtual void addAll(Collection<E, C> &c);;
		virtual void clear();
		virtual bool contains(const E& e) const;
		virtual bool containsAll(Collection<E, C> &c) const;
		virtual bool isEmpty() const;
		virtual void remove(const E& e);
		virtual void removeAll(Collection<E, C> &c);
		virtual void retainAll(Collection<E, C> &c);
		virtual size_t size() const;
		// helper functions
		// for working with range-base for loop
		virtual typename C::iterator begin();
		virtual typename C::iterator end();
		// constructors
		HashSet();
		HashSet(std::initializer_list<E> elements);

	private:
		C container;
		
	};

	// partially template specialization for std::set
	// because we know Set is a collection contains no duplicate element
	// if we use underlying std::vector, std::list as our container in collection
	// when we insert element, we need to check if that element is already exist
	// if it existed, we don't insert it
	// we also know that std::set is already implement this constraint for us
	// so we don't need to check that again in our implementation for add() function
	// that why we need a specalization for our HashSet to work differently when we 
	// using std::set as an underlying container.	 

	template <typename E>
	class HashSet<E, std::set<E>> : public Set<E, std::set<E>> {

	public:

		virtual Iterator<E, std::set<E>> iterator();
		virtual void add(const E& e);
		virtual void addAll(Collection<E, std::set<E>> &c);;
		virtual void clear();
		virtual bool contains(const E& e) const;
		virtual bool containsAll(Collection<E, std::set<E>> &c) const;
		virtual bool isEmpty() const;
		virtual void remove(const E& e);
		virtual void removeAll(Collection<E, std::set<E>> &c);
		virtual void retainAll(Collection<E, std::set<E>> &c);
		virtual size_t size() const;
		// helper functions
		// for working with range-base for loop
		virtual typename std::set<E>::iterator begin();
		virtual typename std::set<E>::iterator end();

		// constructor
		HashSet();
		HashSet(std::initializer_list<E> elements);


	private:
		std::set<E> container;
	};

}




#endif