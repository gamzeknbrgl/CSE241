#include "LinkedList.h"
#include <iostream>

//Implements both queue and list functions
	
namespace myCollection {


	template<typename E, typename C>
	LinkedList<E, C>::LinkedList()
	{
	}

	template<typename E, typename C>
	LinkedList<E, C>::LinkedList(std::initializer_list<E> elements) : container(elements) {}

	//Returns an iterator over the collection 
	template<typename E, typename C>
	Iterator<E, C> LinkedList<E, C>::iterator()
	{
		return Iterator<E, C>(container, container.begin());
	}
	//Ensures that this collection contains the specified element
	template<typename E, typename C>
	void LinkedList<E, C>::add(const E & e)
	{
		container.push_back(e);
	}
	//Adds all of the elements in the specified collection to this collection
	template<typename E, typename C>
	void LinkedList<E, C>::addAll(Collection<E, C>& c)
	{
		for (const auto& e : c) {
			add(e);
		}
	}
	//Removes all of the elements from this collection  
	template<typename E, typename C>
	void LinkedList<E, C>::clear()
	{
		container.clear();
	}
	//Returns true if this collection contains the specified element.
	template<typename E, typename C>
	bool LinkedList<E, C>::contains(const E & e) const
	{
		auto it = std::find(container.begin(), container.end(), e);

		if (it == container.end()) {
			return false;
		}

		return true;
	}
	//Returns true if this collection contains all of the elements in the specified collection.
	template<typename E, typename C>
	bool LinkedList<E, C>::containsAll(Collection<E, C>& c) const
	{
		for (auto& e : c) {
			if (!contains(e)) {
				return false;
			}
		}

		return true;
	}
	//Returns true if this collection contains all of the elements in the specified collection
	template<typename E, typename C>
	bool LinkedList<E, C>::isEmpty() const
	{
		return container.empty();
	}
	//Removes a single instance of the specified element from this collection, if it is present 
	template<typename E, typename C>
	void LinkedList<E, C>::remove(const E & e)
	{
		auto it = std::find(container.begin(), container.end(), e);

		if (it != container.end()) {
			container.erase(it);
		}
	}
	//Removes all of this collection's elements that are also contained in the specified collection
	template<typename E, typename C>
	void LinkedList<E, C>::removeAll(Collection<E, C>& c)
	{
		for (auto& e : c) {
			remove(e);
		}
	}
	//Retains only the elements in this collection that are contained in the specified collection  
	template<typename E, typename C>
	void LinkedList<E, C>::retainAll(Collection<E, C>& c)
	{
		for (auto it = container.begin(); it != container.end();) {
			if (!c.contains(*it)) {
				it = container.erase(it);
			} else {
				++it;
			}
		}
	}
	//Returns the number of elements in this collection. 
	template<typename E, typename C>
	size_t LinkedList<E, C>::size() const
	{
		return container.size();
	}

	template<typename E, typename C>
	E LinkedList<E, C>::element() const
	{
		return container.front();
	}

	template<typename E, typename C>
	void LinkedList<E, C>::offer(E e)
	{
		container.push_back(e);
	}

	template<typename E, typename C>
	E LinkedList<E, C>::poll() throw(std::runtime_error)
	{
		if (isEmpty()) {
			throw std::runtime_error("Collection is empty");
		}

		// get the head value
		auto headValue = *container.begin();

		// then remove first
		remove(headValue);

		return headValue;
	}

	template<typename E, typename C>
	typename C::iterator LinkedList<E, C>::begin()
	{
		return container.begin();
	}

	template<typename E, typename C>
	typename C::iterator LinkedList<E, C>::end()
	{
		return container.end();
	}

	//partially template specialization for std::set 
	template<typename E>
	LinkedList<E, std::set<E>>::LinkedList()
	{
	}

	template<typename E>
	LinkedList<E, std::set<E>>::LinkedList(std::initializer_list<E> elements) : container(elements) {}

	template<typename E>
	Iterator<E, std::set<E>> LinkedList<E, std::set<E>>::iterator()
	{
		return Iterator<E, std::set<E>>(container, container.begin());
	}

	template<typename E>
	void LinkedList<E, std::set<E>>::add(const E & e)
	{
		container.insert(e);
	}

	template<typename E>
	void LinkedList<E, std::set<E>>::addAll(Collection<E, std::set<E>>& c)
	{
		for (auto& e : c) {
			container.insert(e);
		}
	}

	template<typename E>
	void LinkedList<E, std::set<E>>::clear()
	{
		container.clear();
	}

	template<typename E>
	bool LinkedList<E, std::set<E>>::contains(const E & e) const
	{
		bool isContain = container.find(e) != container.end();
		return isContain;
	}

	template<typename E>
	bool LinkedList<E, std::set<E>>::containsAll(Collection<E, std::set<E>>& c) const
	{
		for (auto& e : c) {
			if (container.find(e) == container.end()) {
				return false;
			}
		}

		return true;
	}

	template<typename E>
	bool LinkedList<E, std::set<E>>::isEmpty() const
	{
		return container.empty();
	}

	template<typename E>
	void LinkedList<E, std::set<E>>::remove(const E & e)
	{
		container.erase(e);
	}

	template<typename E>
	void LinkedList<E, std::set<E>>::removeAll(Collection<E, std::set<E>>& c)
	{
		for (auto& e : c) {
			container.erase(e);
		}
	}

	template<typename E>
	void LinkedList<E, std::set<E>>::retainAll(Collection<E, std::set<E>>& c)
	{
		for (auto it = container.begin(); it != container.end();) {
			if (!c.contains(*it)) {
				container.erase(it++);
			} else {
				++it;
			}
		}
	}
	template<typename E>
	size_t LinkedList<E, std::set<E>>::size() const
	{
		return container.size();
	}

	template<typename E>
	E LinkedList<E, std::set<E>>::element() const
	{
		return *container.begin();
	}

	template<typename E>
	void LinkedList<E, std::set<E>>::offer(E e)
	{
		container.insert(e);
	}

	template<typename E>
	E LinkedList<E, std::set<E>>::poll() throw(std::runtime_error)
	{
		if (isEmpty()) {
			throw std::runtime_error("Collection is empty");
		}

		// get the head value
		auto headValue = element();

		// then remove first
		remove(headValue);

		return headValue;
	}

	template<typename E>
	typename std::set<E>::iterator LinkedList<E, std::set<E>>::begin()
	{
		return container.begin();
	}

	template<typename E>
	typename std::set<E>::iterator LinkedList<E, std::set<E>>::end()
	{
		return container.end();
	}
	
}