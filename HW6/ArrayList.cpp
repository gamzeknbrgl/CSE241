#include "ArrayList.h"
#include <iostream>


namespace myCollection {

	template<typename E, typename C>
	ArrayList<E, C>::ArrayList()
	{
	}

	template<typename E, typename C>
	ArrayList<E, C>::ArrayList(std::initializer_list<E> elements) : container(elements) {}

	//Returns an iterator over the collection 
	template<typename E, typename C>
	Iterator<E, C> ArrayList<E, C>::iterator()
	{
		return Iterator<E, C>(container, container.begin());
	}
	//Ensures that this collection contains the specified element 
	template<typename E, typename C>
	void ArrayList<E, C>::add(const E & e)
	{
		container.push_back(e);
	}
	//Adds all of the elements in the specified collection to this collection 
	template<typename E, typename C>
	void ArrayList<E, C>::addAll(Collection<E, C>& c)
	{
		
		for (auto& e : c) {
			add(e);
		}
	}
	//Removes all of the elements from this collection 
	template<typename E, typename C>
	void ArrayList<E, C>::clear()
	{
		container.clear();
	}
	//Returns true if this collection contains the specified element.
	template<typename E, typename C>
	bool ArrayList<E, C>::contains(const E & e) const
	{
		auto it = std::find(container.begin(), container.end(), e);

		if (it == container.end()) {
			return false;
		}

		return true;
	}
	//Returns true if this collection contains all of the elements in the specified collection. 
	template<typename E, typename C>
	bool ArrayList<E, C>::containsAll(Collection<E, C>& c) const
	{
		for (auto& e : c) {
			if (!contains(e)) {
				return false;
			}
		}

		return true;
	}
	//Returns true if this collection contains no elements. 
	template<typename E, typename C>
	bool ArrayList<E, C>::isEmpty() const
	{
		return container.empty();
	}
	//Removes a single instance of the specified element from this collection, if it is present  
	template<typename E, typename C>
	void ArrayList<E, C>::remove(const E & e)
	{
		auto it = std::find(container.begin(), container.end(), e);

		if (it != container.end()) {
			container.erase(it);
		}
	}
	//Removes all of this collection's elements that are also contained in the specified collection 
	template<typename E, typename C>
	void ArrayList<E, C>::removeAll(Collection<E, C>& c)
	{
		for (auto& e : c) {
			remove(e);
		}
	}
	//Retains only the elements in this collection that are contained in the specified collection 
	template<typename E, typename C>
	void ArrayList<E, C>::retainAll(Collection<E, C>& c)
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
	size_t ArrayList<E, C>::size() const
	{
		return container.size();
	}

	template<typename E, typename C>
	typename C::iterator ArrayList<E, C>::begin()
	{
		return container.begin();
	}

	template<typename E, typename C>
	typename C::iterator ArrayList<E, C>::end()
	{
		return container.end();
	}

	// partially template specilization for std::set 

	template<typename E>
	ArrayList<E, std::set<E>>::ArrayList()
	{
	}

	template<typename E>
	ArrayList<E, std::set<E>>::ArrayList(std::initializer_list<E> elements) : container(elements) {}

	template<typename E>
	Iterator<E, std::set<E>> ArrayList<E, std::set<E>>::iterator()
	{
		return Iterator<E, std::set<E>>(container, container.begin());
	}

	template<typename E>
	void ArrayList<E, std::set<E>>::add(const E & e)
	{
		container.insert(e);
	}

	template<typename E>
	void ArrayList<E, std::set<E>>::addAll(Collection<E, std::set<E>>& c)
	{
		
		
		for (auto& e : c) {
			add(e);
		}
	}

	template<typename E>
	void ArrayList<E, std::set<E>>::clear()
	{
		container.clear();
	}

	template<typename E>
	bool ArrayList<E, std::set<E>>::contains(const E & e) const
	{
		auto it = std::find(container.begin(), container.end(), e);

		if (it == container.end()) {
			return false;
		}

		return true;
	}

	template<typename E>
	bool ArrayList<E, std::set<E>>::containsAll(Collection<E, std::set<E>>& c) const
	{
		for (auto& e : c) {
			if (!contains(e)) {
				return false;
			}
		}

		return true;
	}

	template<typename E>
	bool ArrayList<E, std::set<E>>::isEmpty() const
	{
		return container.empty();
	}

	template<typename E>
	void ArrayList<E, std::set<E>>::remove(const E & e)
	{
		auto it = std::find(container.begin(), container.end(), e);

		if (it != container.end()) {
			container.erase(it);
		}
	}

	template<typename E>
	void ArrayList<E, std::set<E>>::removeAll(Collection<E, std::set<E>>& c)
	{
		for (auto& e : c) {
			remove(e);
		}
	}

	template<typename E>
	void ArrayList<E, std::set<E>>::retainAll(Collection<E, std::set<E>>& c)
	{
		for (auto it = container.begin(); it != container.end();) {
			if (!c.contains(*it)) {
				it = container.erase(it);
			} else {
				++it;
			}
		}

	}

	template<typename E>
	size_t ArrayList<E, std::set<E>>::size() const
	{
		return container.size();
	}

	template<typename E>
	typename std::set<E>::iterator ArrayList<E, std::set<E>>::begin()
	{
		return container.begin();
	}

	template<typename E>
	typename std::set<E>::iterator ArrayList<E, std::set<E>>::end()
	{
		return container.end();
	}


}