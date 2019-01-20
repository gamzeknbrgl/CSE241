#include <string>

// Because of template instantiate problem, we need to include these implementation in header file

#include "HashSet.cpp"
#include "Iterator.cpp"
#include "ArrayList.cpp"
#include "LinkedList.cpp"

// Helper function for priting element
template<typename E, typename C>
void PrintAllElement(myCollection::Collection<E, C>& collection, const char* collectionName)
{
	std::cout << "Current element " << collectionName << ": ";
	std::cout << "[ ";

	for(const auto& e : collection){
		std::cout << e << " ";
	}
	
	std::cout << " ]";
	std::cout << std::endl;
}

void TestHashSetWithVectorInt()
{
	std::cout << "TEST HASHSET WITH VECTOR<INT>: \n";

	myCollection::HashSet<int> hashSet1;

	hashSet1.add(1);
	hashSet1.add(2);
	hashSet1.add(5);
	hashSet1.add(10);
	hashSet1.add(15);
	hashSet1.add(20);

	PrintAllElement(hashSet1, "hashSet1");

	int elementToRemove = 15;
	std::cout << std::boolalpha << "Is hashset1 empty: " << hashSet1.isEmpty() << "\n";
	std::cout << "Current size: " << hashSet1.size() << "\n";
	PrintAllElement(hashSet1, "hashSet1");

	std::cout << "Remove element with value: " << elementToRemove << "\n";

	hashSet1.remove(elementToRemove);

	std::cout << "Current size: " << hashSet1.size() << "\n";
	PrintAllElement(hashSet1, "hashSet1");

	myCollection::HashSet<int> hashSet2{ 25,30,34,65 };
	PrintAllElement(hashSet2, "hashSet2");
	std::cout << "Add hashset2 to hashset1 \n";
	hashSet1.addAll(hashSet2);

	std::cout << "Current size: " << hashSet1.size() << "\n";
	PrintAllElement(hashSet1, "hashSet1");

	int elementToCheck = 34;
	std::cout << std::boolalpha << "Hashset1 contain element " << elementToCheck << " :" << hashSet1.contains(elementToCheck) << "\n";

	std::cout << "Remove all from hashset1 with element from hashset2\n";
	hashSet1.removeAll(hashSet2);
	std::cout << "Current size: " << hashSet1.size() << "\n";
	PrintAllElement(hashSet1, "hashSet1");

	// add it again to test retainAll function

	std::cout << "Add hashSet2 to hashset1 again\n";
	hashSet1.addAll(hashSet2);
	PrintAllElement(hashSet1, "hashSet1");
	std::cout << "Retain all element from hashset2 in hashset1\n";
	hashSet1.retainAll(hashSet2);
	std::cout << "Current size: " << hashSet1.size() << "\n";
	PrintAllElement(hashSet1, "hashSet1");

	// test iterator
	auto it = hashSet1.iterator();

	try
	{
		std::cout << "Iterator has next element: " << it.hasNext() << "\n";
		std::cout << "Next element value: " << it.next() << "\n";
		std::cout << "Next element value: " << it.next() << "\n";
		std::cout << "Next element value: " << it.next() << "\n";
		std::cout << "Remove last element\n";
		it.remove();
		PrintAllElement(hashSet1, "hashSet1");
		std::cout << "Next element value: " << it.next() << "\n";

	} catch (const std::exception& e)
	{
		auto what = e.what();
		std::cout << "Exception is thrown: " << what << "\n";
	}

	std::cout << "************************************************************************************\n";

}


void TestHashSetWithVectorString()
{
	std::cout << "TEST HASHSET WITH VECTOR<STRING>: \n";

	myCollection::HashSet<std::string> hashSet1;

	hashSet1.add("four");
	hashSet1.add("years");
	hashSet1.add("no");
	hashSet1.add("call");
	hashSet1.add("from");
	hashSet1.add("you");


	PrintAllElement(hashSet1, "hashSet1");

	std::string elementToRemove{ "call" };
	std::cout << std::boolalpha << "Is hashset1 empty: " << hashSet1.isEmpty() << "\n";
	std::cout << "Current size: " << hashSet1.size() << "\n";
	PrintAllElement(hashSet1, "hashSet1");

	std::cout << "Remove element with value: " << elementToRemove << "\n";

	hashSet1.remove(elementToRemove);

	std::cout << "Current size: " << hashSet1.size() << "\n";
	PrintAllElement(hashSet1, "hashSet1");

	myCollection::HashSet<std::string> hashSet2{ "i","am","still", "waiting" };
	PrintAllElement(hashSet2, "hashSet2");
	std::cout << "Add hashset2 to hashset1 \n";
	hashSet1.addAll(hashSet2);

	std::cout << "Current size: " << hashSet1.size() << "\n";
	PrintAllElement(hashSet1, "hashSet1");

	std::string elementToCheck{ "hey" };
	std::cout << std::boolalpha << "Hashset1 contain element " << elementToCheck << " :" << hashSet1.contains(elementToCheck) << "\n";

	std::cout << "Remove all from hashset1 with element from hashset2\n";
	hashSet1.removeAll(hashSet2);
	std::cout << "Current size: " << hashSet1.size() << "\n";
	PrintAllElement(hashSet1, "hashSet1");

	// add it again to test retainAll function

	std::cout << "Add hashSet2 to hashset1 again\n";
	hashSet1.addAll(hashSet2);
	PrintAllElement(hashSet1, "hashSet1");
	std::cout << "Retain all element from hashset2 in hashset1\n";
	hashSet1.retainAll(hashSet2);
	std::cout << "Current size: " << hashSet1.size() << "\n";
	PrintAllElement(hashSet1, "hashSet1");

	// test iterator
	auto it = hashSet1.iterator();

	try
	{
		std::cout << "Iterator has next element: " << it.hasNext() << "\n";
		std::cout << "Next element value: " << it.next() << "\n";
		std::cout << "Next element value: " << it.next() << "\n";
		std::cout << "Next element value: " << it.next() << "\n";
		std::cout << "Remove last element\n";
		it.remove();
		PrintAllElement(hashSet1, "hashSet1");
		std::cout << "Next element value: " << it.next() << "\n";

	} catch (const std::exception& e)
	{
		auto what = e.what();
		std::cout << "Exception is thrown: " << what << "\n";
	}

	std::cout << "************************************************************************************\n";
}


void TestHashSetWithListInt()
{
	std::cout << "TEST HASHSET WITH LIST<INT>: \n";

	myCollection::HashSet<int, std::list<int>> hashSet1;

	hashSet1.add(1);
	hashSet1.add(2);
	hashSet1.add(5);
	hashSet1.add(10);
	hashSet1.add(15);
	hashSet1.add(20);

	PrintAllElement(hashSet1, "hashSet1");

	int elementToRemove = 15;
	std::cout << std::boolalpha << "Is hashset1 empty: " << hashSet1.isEmpty() << "\n";
	std::cout << "Current size: " << hashSet1.size() << "\n";
	PrintAllElement(hashSet1, "hashSet1");

	std::cout << "Remove element with value: " << elementToRemove << "\n";

	hashSet1.remove(elementToRemove);

	std::cout << "Current size: " << hashSet1.size() << "\n";
	PrintAllElement(hashSet1, "hashSet1");

	myCollection::HashSet<int, std::list<int>> hashSet2{ 25,30,34,65 };
	PrintAllElement(hashSet2, "hashSet2");
	std::cout << "Add hashset2 to hashset1 \n";
	hashSet1.addAll(hashSet2);

	std::cout << "Current size: " << hashSet1.size() << "\n";
	PrintAllElement(hashSet1, "hashSet1");

	int elementToCheck = 34;
	std::cout << std::boolalpha << "Hashset1 contain element " << elementToCheck << " :" << hashSet1.contains(elementToCheck) << "\n";

	std::cout << "Remove all from hashset1 with element from hashset2\n";
	hashSet1.removeAll(hashSet2);
	std::cout << "Current size: " << hashSet1.size() << "\n";
	PrintAllElement(hashSet1, "hashSet1");

	// add it again to test retainAll function

	std::cout << "Add hashSet2 to hashset1 again\n";
	hashSet1.addAll(hashSet2);
	PrintAllElement(hashSet1, "hashSet1");
	std::cout << "Retain all element from hashset2 in hashset1\n";
	hashSet1.retainAll(hashSet2);
	std::cout << "Current size: " << hashSet1.size() << "\n";
	PrintAllElement(hashSet1, "hashSet1");

	// test iterator
	auto it = hashSet1.iterator();

	try
	{
		std::cout << "Iterator has next element: " << it.hasNext() << "\n";
		std::cout << "Next element value: " << it.next() << "\n";
		std::cout << "Next element value: " << it.next() << "\n";
		std::cout << "Next element value: " << it.next() << "\n";
		std::cout << "Remove last element\n";
		it.remove();
		PrintAllElement(hashSet1, "hashSet1");
		std::cout << "Next element value: " << it.next() << "\n";

	} catch (const std::exception& e)
	{
		auto what = e.what();
		std::cout << "Exception is thrown: " << what << "\n";
	}

	std::cout << "************************************************************************************\n";

}

void TestHashSetWithListString()
{
	std::cout << "TEST HASHSET WITH LIST<STRING>: \n";

	myCollection::HashSet<std::string, std::list<std::string>> hashSet1;

	hashSet1.add("four");
	hashSet1.add("years");
	hashSet1.add("no");
	hashSet1.add("call");
	hashSet1.add("from");
	hashSet1.add("you");


	PrintAllElement(hashSet1, "hashSet1");

	std::string elementToRemove{ "call" };
	std::cout << std::boolalpha << "Is hashset1 empty: " << hashSet1.isEmpty() << "\n";
	std::cout << "Current size: " << hashSet1.size() << "\n";
	PrintAllElement(hashSet1, "hashSet1");

	std::cout << "Remove element with value: " << elementToRemove << "\n";

	hashSet1.remove(elementToRemove);

	std::cout << "Current size: " << hashSet1.size() << "\n";
	PrintAllElement(hashSet1, "hashSet1");

	myCollection::HashSet<std::string, std::list<std::string>> hashSet2{ "i","am","still", "waiting" };
	PrintAllElement(hashSet2, "hashSet2");
	std::cout << "Add hashset2 to hashset 1 \n";
	hashSet1.addAll(hashSet2);

	std::cout << "Current size: " << hashSet1.size() << "\n";
	PrintAllElement(hashSet1, "hashSet1");

	std::string elementToCheck{ "hey" };
	std::cout << std::boolalpha << "Hashset1 contain element " << elementToCheck << " :" << hashSet1.contains(elementToCheck) << "\n";

	std::cout << "Remove all from hashset1 with element from hashset2\n";
	hashSet1.removeAll(hashSet2);
	std::cout << "Current size: " << hashSet1.size() << "\n";
	PrintAllElement(hashSet1, "hashSet1");

	// add it again to test retainAll function

	std::cout << "Add hashSet2 to hashset1 again\n";
	hashSet1.addAll(hashSet2);
	PrintAllElement(hashSet1, "hashSet1");
	std::cout << "Retain all element from hashset2 in hashset1\n";
	hashSet1.retainAll(hashSet2);
	std::cout << "Current size: " << hashSet1.size() << "\n";
	PrintAllElement(hashSet1, "hashSet1");

	// test iterator
	auto it = hashSet1.iterator();

	try
	{
		std::cout << "Iterator has next element: " << it.hasNext() << "\n";
		std::cout << "Next element value: " << it.next() << "\n";
		std::cout << "Next element value: " << it.next() << "\n";
		std::cout << "Next element value: " << it.next() << "\n";
		std::cout << "Remove last element\n";
		it.remove();
		PrintAllElement(hashSet1, "hashSet1");
		std::cout << "Next element value: " << it.next() << "\n";

	} catch (const std::exception& e)
	{
		auto what = e.what();
		std::cout << "Exception is thrown: " << what << "\n";
	}

	std::cout << "************************************************************************************\n";
}

void TestHashSetWithSetInt()
{
	std::cout << "TEST HASHSET WITH SET<INT>: \n";

	myCollection::HashSet<int, std::set<int>> hashSet1;

	hashSet1.add(1);
	hashSet1.add(2);
	hashSet1.add(5);
	hashSet1.add(10);
	hashSet1.add(15);
	hashSet1.add(20);

	PrintAllElement(hashSet1, "hashSet1");

	int elementToRemove = 15;
	std::cout << std::boolalpha << "Is hashset1 empty: " << hashSet1.isEmpty() << "\n";
	std::cout << "Current size: " << hashSet1.size() << "\n";
	PrintAllElement(hashSet1, "hashSet1");

	std::cout << "Remove element with value: " << elementToRemove << "\n";

	hashSet1.remove(elementToRemove);

	std::cout << "Current size: " << hashSet1.size() << "\n";
	PrintAllElement(hashSet1, "hashSet1");

	myCollection::HashSet<int, std::set<int>> hashSet2{ 25,30,34,65 };
	PrintAllElement(hashSet2, "hashSet2");
	std::cout << "Add hashset2 to hashset 1 \n";
	hashSet1.addAll(hashSet2);

	std::cout << "Current size: " << hashSet1.size() << "\n";
	PrintAllElement(hashSet1, "hashSet1");

	int elementToCheck = 34;
	std::cout << std::boolalpha << "Hashset1 contain element " << elementToCheck << " :" << hashSet1.contains(elementToCheck) << "\n";

	std::cout << "Remove all from hashset1 with element from hashset2\n";
	hashSet1.removeAll(hashSet2);
	std::cout << "Current size: " << hashSet1.size() << "\n";
	PrintAllElement(hashSet1, "hashSet1");

	// add it again to test retainAll function

	PrintAllElement(hashSet2, "hashSet2");
	std::cout << "Add hashSet2 to hashset1 again\n";
	hashSet1.addAll(hashSet2);
	PrintAllElement(hashSet1, "hashSet1");
	std::cout << "Retain all element from hashset2 in hashset1\n";
	hashSet1.retainAll(hashSet2);
	std::cout << "Current size: " << hashSet1.size() << "\n";
	PrintAllElement(hashSet1, "hashSet1");

	// test iterator
	auto it = hashSet1.iterator();

	try
	{
		std::cout << "Iterator has next element: " << it.hasNext() << "\n";
		std::cout << "Next element value: " << it.next() << "\n";
		std::cout << "Next element value: " << it.next() << "\n";
		std::cout << "Next element value: " << it.next() << "\n";
		std::cout << "Remove last element\n";
		it.remove();
		PrintAllElement(hashSet1, "hashSet1");
		std::cout << "Next element value: " << it.next() << "\n";

	} catch (const std::exception& e)
	{
		auto what = e.what();
		std::cout << "Exception is thrown: " << what << "\n";
	}

	std::cout << "************************************************************************************\n";

}

void TestHashSetWithSetString()
{
	std::cout << "TEST HASHSET WITH SET<STRING>: \n";

	myCollection::HashSet<std::string, std::set<std::string>> hashSet1;

	hashSet1.add("four");
	hashSet1.add("years");
	hashSet1.add("no");
	hashSet1.add("call");
	hashSet1.add("from");
	hashSet1.add("you");


	PrintAllElement(hashSet1, "hashSet1");

	std::string elementToRemove{ "call" };
	std::cout << std::boolalpha << "Is hashset1 empty: " << hashSet1.isEmpty() << "\n";
	std::cout << "Current size: " << hashSet1.size() << "\n";
	PrintAllElement(hashSet1, "hashSet1");

	std::cout << "Remove element with value: " << elementToRemove << "\n";

	hashSet1.remove(elementToRemove);

	std::cout << "Current size: " << hashSet1.size() << "\n";
	PrintAllElement(hashSet1, "hashSet1");

	myCollection::HashSet<std::string, std::set<std::string>> hashSet2{ "i","am","still", "waiting" };
	PrintAllElement(hashSet2, "hashSet2");
	std::cout << "Add hashset2 to hashset 1 \n";
	hashSet1.addAll(hashSet2);

	std::cout << "Current size: " << hashSet1.size() << "\n";
	PrintAllElement(hashSet1, "hashSet1");

	std::string elementToCheck{ "ya" };
	std::cout << std::boolalpha << "Hashset1 contain element " << elementToCheck << " :" << hashSet1.contains(elementToCheck) << "\n";

	std::cout << "Remove all from hashset1 with element from hashset2\n";
	hashSet1.removeAll(hashSet2);
	std::cout << "Current size: " << hashSet1.size() << "\n";
	PrintAllElement(hashSet1, "hashSet1");

	// add it again to test retainAll function

	std::cout << "Add hashSet2 to hashset1 again\n";
	hashSet1.addAll(hashSet2);
	PrintAllElement(hashSet1, "hashSet1");
	std::cout << "Retain all element from hashset2 in hashset1\n";
	hashSet1.retainAll(hashSet2);
	std::cout << "Current size: " << hashSet1.size() << "\n";
	PrintAllElement(hashSet1, "hashSet1");

	// test iterator
	auto it = hashSet1.iterator();

	try
	{
		std::cout << "Iterator has next element: " << it.hasNext() << "\n";
		std::cout << "Next element value: " << it.next() << "\n";
		std::cout << "Next element value: " << it.next() << "\n";
		std::cout << "Next element value: " << it.next() << "\n";
		std::cout << "Remove last element\n";
		it.remove();
		PrintAllElement(hashSet1, "hashSet1");
		std::cout << "Next element value: " << it.next() << "\n";

	} catch (const std::exception& e)
	{
		auto what = e.what();
		std::cout << "Exception is thrown: " << what << "\n";
	}

	std::cout << "************************************************************************************\n";
}


//*****************************************************ArrayList******************************************

void TestArrayListWithVectorInt()
{
	std::cout << "TEST ARRAYLIST WITH VECTOR<INT>: \n";

	myCollection::ArrayList<int> arrayList1;

	arrayList1.add(1);
	arrayList1.add(2);
	arrayList1.add(5);
	arrayList1.add(10);
	arrayList1.add(15);
	arrayList1.add(20);

	PrintAllElement(arrayList1, "arrayList1");

	int elementToRemove = 15;
	std::cout << std::boolalpha << "Is arrayList1 empty: " << arrayList1.isEmpty() << "\n";
	std::cout << "Current size: " << arrayList1.size() << "\n";
	PrintAllElement(arrayList1, "arrayList1");

	std::cout << "Remove element with value: " << elementToRemove << "\n";

	arrayList1.remove(elementToRemove);

	std::cout << "Current size: " << arrayList1.size() << "\n";
	PrintAllElement(arrayList1, "arrayList1");

	myCollection::ArrayList<int> arrayList2{ 25,30,34,65 };
	PrintAllElement(arrayList2, "arrayList2");
	std::cout << "Add arrayList2 to hashset 1 \n";
	arrayList1.addAll(arrayList2);

	std::cout << "Current size: " << arrayList1.size() << "\n";
	PrintAllElement(arrayList1, "arrayList1");

	int elementToCheck = 34;
	std::cout << std::boolalpha << "arrayList1 contain element " << elementToCheck << " :" << arrayList1.contains(elementToCheck) << "\n";

	std::cout << "Remove all from arrayList1 with element from arrayList2\n";
	arrayList1.removeAll(arrayList2);
	std::cout << "Current size: " << arrayList1.size() << "\n";
	PrintAllElement(arrayList1, "arrayList1");

	// add it again to test retainAll function

	std::cout << "Add arrayList2 to arrayList1 again\n";
	arrayList1.addAll(arrayList2);
	PrintAllElement(arrayList1, "arrayList1");
	std::cout << "Retain all element from arrayList2 in arrayList1\n";
	arrayList1.retainAll(arrayList2);
	std::cout << "Current size: " << arrayList1.size() << "\n";
	PrintAllElement(arrayList1, "arrayList1");

	// test iterator
	auto it = arrayList1.iterator();

	try
	{
		std::cout << "Iterator has next element: " << it.hasNext() << "\n";
		std::cout << "Next element value: " << it.next() << "\n";
		std::cout << "Next element value: " << it.next() << "\n";
		std::cout << "Next element value: " << it.next() << "\n";
		std::cout << "Remove last element\n";
		it.remove();
		PrintAllElement(arrayList1, "arrayList1");
		std::cout << "Next element value: " << it.next() << "\n";

	} catch (const std::exception& e)
	{
		auto what = e.what();
		std::cout << "Exception is thrown: " << what << "\n";
	}

	std::cout << "************************************************************************************\n";

}

void TestArrayListWithVectorString()
{
	std::cout << "TEST ARRAYLIST WITH VECTOR<STRING>: \n";

	myCollection::HashSet<std::string> arrayList1;

	arrayList1.add("four");
	arrayList1.add("years");
	arrayList1.add("no");
	arrayList1.add("call");
	arrayList1.add("from");
	arrayList1.add("you");


	PrintAllElement(arrayList1, "arrayList1");

	std::string elementToRemove{ "call" };
	std::cout << std::boolalpha << "Is arrayList1 empty: " << arrayList1.isEmpty() << "\n";
	std::cout << "Current size: " << arrayList1.size() << "\n";
	PrintAllElement(arrayList1, "arrayList1");

	std::cout << "Remove element with value: " << elementToRemove << "\n";

	arrayList1.remove(elementToRemove);

	std::cout << "Current size: " << arrayList1.size() << "\n";
	PrintAllElement(arrayList1, "arrayList1");

	myCollection::HashSet<std::string> arrayList2{ "i","am","still", "waiting" };
	PrintAllElement(arrayList2, "arrayList2");
	std::cout << "Add arrayList2 to hashset 1 \n";
	arrayList1.addAll(arrayList2);

	std::cout << "Current size: " << arrayList1.size() << "\n";
	PrintAllElement(arrayList1, "arrayList1");

	std::string elementToCheck{ "ya" };
	std::cout << std::boolalpha << "arrayList1 contain element " << elementToCheck << " :" << arrayList1.contains(elementToCheck) << "\n";

	std::cout << "Remove all from arrayList1 with element from arrayList2\n";
	arrayList1.removeAll(arrayList2);
	std::cout << "Current size: " << arrayList1.size() << "\n";
	PrintAllElement(arrayList1, "arrayList1");

	// add it again to test retainAll function

	std::cout << "Add arrayList2 to arrayList1 again\n";
	arrayList1.addAll(arrayList2);
	PrintAllElement(arrayList1, "arrayList1");
	std::cout << "Retain all element from arrayList2 in arrayList1\n";
	arrayList1.retainAll(arrayList2);
	std::cout << "Current size: " << arrayList1.size() << "\n";
	PrintAllElement(arrayList1, "arrayList1");

	// test iterator
	auto it = arrayList1.iterator();

	try
	{
		std::cout << "Iterator has next element: " << it.hasNext() << "\n";
		std::cout << "Next element value: " << it.next() << "\n";
		std::cout << "Next element value: " << it.next() << "\n";
		std::cout << "Next element value: " << it.next() << "\n";
		std::cout << "Remove last element\n";
		it.remove();
		std::cout << "Iterator has next element: " << it.hasNext() << "\n";
		PrintAllElement(arrayList1, "arrayList1");
		std::cout << "Next element value: " << it.next() << "\n";

	} catch (const std::exception& e)
	{
		auto what = e.what();
		std::cout << "Exception is thrown: " << what << "\n";
	}

	std::cout << "************************************************************************************\n";
}

void TestArrayListWithListInt()
{
	std::cout << "TEST ARRAYLIST WITH LIST<INT>: \n";

	myCollection::ArrayList<int, std::list<int>> arrayList1;

	arrayList1.add(1);
	arrayList1.add(2);
	arrayList1.add(5);
	arrayList1.add(10);
	arrayList1.add(15);
	arrayList1.add(20);

	PrintAllElement(arrayList1, "arrayList1");

	int elementToRemove = 15;
	std::cout << std::boolalpha << "Is arrayList1 empty: " << arrayList1.isEmpty() << "\n";
	std::cout << "Current size: " << arrayList1.size() << "\n";
	PrintAllElement(arrayList1, "arrayList1");

	std::cout << "Remove element with value: " << elementToRemove << "\n";

	arrayList1.remove(elementToRemove);

	std::cout << "Current size: " << arrayList1.size() << "\n";
	PrintAllElement(arrayList1, "arrayList1");

	myCollection::ArrayList<int, std::list<int>> arrayList2{ 25,30,34,65 };
	PrintAllElement(arrayList2, "arrayList2");
	std::cout << "Add arrayList2 to arrayList1 \n";
	arrayList1.addAll(arrayList2);

	std::cout << "Current size: " << arrayList1.size() << "\n";
	PrintAllElement(arrayList1, "arrayList1");

	int elementToCheck = 34;
	std::cout << std::boolalpha << "arrayList1 contain element " << elementToCheck << " :" << arrayList1.contains(elementToCheck) << "\n";

	std::cout << "Remove all from arrayList1 with element from arrayList2\n";
	arrayList1.removeAll(arrayList2);
	std::cout << "Current size: " << arrayList1.size() << "\n";
	PrintAllElement(arrayList1, "arrayList1");

	// add it again to test retainAll function

	std::cout << "Add arrayList2 to arrayList1 again\n";
	arrayList1.addAll(arrayList2);
	PrintAllElement(arrayList1, "arrayList1");
	std::cout << "Retain all element from arrayList2 in arrayList1\n";
	arrayList1.retainAll(arrayList2);
	std::cout << "Current size: " << arrayList1.size() << "\n";
	PrintAllElement(arrayList1, "arrayList1");

	// test iterator
	auto it = arrayList1.iterator();

	try
	{
		std::cout << "Iterator has next element: " << it.hasNext() << "\n";
		std::cout << "Next element value: " << it.next() << "\n";
		std::cout << "Next element value: " << it.next() << "\n";
		std::cout << "Next element value: " << it.next() << "\n";
		std::cout << "Remove last element\n";
		it.remove();
		PrintAllElement(arrayList1, "arrayList1");
		std::cout << "Next element value: " << it.next() << "\n";

	} catch (const std::exception& e)
	{
		auto what = e.what();
		std::cout << "Exception is thrown: " << what << "\n";
	}

	std::cout << "************************************************************************************\n";

}

void TestArrayListWithListString()
{
	std::cout << "TEST ARRAYLIST WITH LIST<STRING>: \n";

	myCollection::HashSet<std::string, std::list<std::string>> arrayList1;

	arrayList1.add("four");
	arrayList1.add("years");
	arrayList1.add("no");
	arrayList1.add("call");
	arrayList1.add("from");
	arrayList1.add("you");


	PrintAllElement(arrayList1, "arrayList1");

	std::string elementToRemove{ "call" };
	std::cout << std::boolalpha << "Is arrayList1 empty: " << arrayList1.isEmpty() << "\n";
	std::cout << "Current size: " << arrayList1.size() << "\n";
	PrintAllElement(arrayList1, "arrayList1");

	std::cout << "Remove element with value: " << elementToRemove << "\n";

	arrayList1.remove(elementToRemove);

	std::cout << "Current size: " << arrayList1.size() << "\n";
	PrintAllElement(arrayList1, "arrayList1");

	myCollection::HashSet<std::string, std::list<std::string>> arrayList2{ "i","am","still", "waiting" };
	PrintAllElement(arrayList2, "arrayList2");
	std::cout << "Add arrayList2 to hashset 1 \n";
	arrayList1.addAll(arrayList2);

	std::cout << "Current size: " << arrayList1.size() << "\n";
	PrintAllElement(arrayList1, "arrayList1");

	std::string elementToCheck{ "hey" };
	std::cout << std::boolalpha << "arrayList1 contain element " << elementToCheck << " :" << arrayList1.contains(elementToCheck) << "\n";

	std::cout << "Remove all from arrayList1 with element from arrayList2\n";
	arrayList1.removeAll(arrayList2);
	std::cout << "Current size: " << arrayList1.size() << "\n";
	PrintAllElement(arrayList1, "arrayList1");

	// add it again to test retainAll function

	std::cout << "Add arrayList2 to arrayList1 again\n";
	arrayList1.addAll(arrayList2);
	PrintAllElement(arrayList1, "arrayList1");
	std::cout << "Retain all element from arrayList2 in arrayList1\n";
	arrayList1.retainAll(arrayList2);
	std::cout << "Current size: " << arrayList1.size() << "\n";
	PrintAllElement(arrayList1, "arrayList1");

	// test iterator
	auto it = arrayList1.iterator();

	try
	{
		std::cout << "Iterator has next element: " << it.hasNext() << "\n";
		std::cout << "Next element value: " << it.next() << "\n";
		std::cout << "Next element value: " << it.next() << "\n";
		std::cout << "Next element value: " << it.next() << "\n";
		std::cout << "Remove last element\n";
		it.remove();
		std::cout << "Iterator has next element: " << it.hasNext() << "\n";
		PrintAllElement(arrayList1, "arrayList1");
		std::cout << "Next element value: " << it.next() << "\n";

	} catch (const std::exception& e)
	{
		auto what = e.what();
		std::cout << "Exception is thrown: " << what << "\n";
	}

	std::cout << "************************************************************************************\n";
}

void TestArrayListWithSetInt()
{
	std::cout << "TEST ARRAYLIST WITH SET<INT>: \n";

	myCollection::ArrayList<int, std::set<int>> arrayList1;

	arrayList1.add(1);
	arrayList1.add(2);
	arrayList1.add(5);
	arrayList1.add(10);
	arrayList1.add(15);
	arrayList1.add(20);

	PrintAllElement(arrayList1, "arrayList1");

	int elementToRemove = 15;
	std::cout << std::boolalpha << "Is arrayList1 empty: " << arrayList1.isEmpty() << "\n";
	std::cout << "Current size: " << arrayList1.size() << "\n";
	PrintAllElement(arrayList1, "arrayList1");

	std::cout << "Remove element with value: " << elementToRemove << "\n";

	arrayList1.remove(elementToRemove);

	std::cout << "Current size: " << arrayList1.size() << "\n";
	PrintAllElement(arrayList1, "arrayList1");

	myCollection::ArrayList<int, std::set<int>> arrayList2{ 25,30,34,65 };
	PrintAllElement(arrayList2, "arrayList2");
	std::cout << "Add arrayList2 to arrayList1 \n";
	arrayList1.addAll(arrayList2);

	std::cout << "Current size: " << arrayList1.size() << "\n";
	PrintAllElement(arrayList1, "arrayList1");

	int elementToCheck = 34;
	std::cout << std::boolalpha << "arrayList1 contain element " << elementToCheck << " :" << arrayList1.contains(elementToCheck) << "\n";

	std::cout << "Remove all from arrayList1 with element from arrayList2\n";
	arrayList1.removeAll(arrayList2);
	std::cout << "Current size: " << arrayList1.size() << "\n";
	PrintAllElement(arrayList1, "arrayList1");

	// add it again to test retainAll function

	std::cout << "Add arrayList2 to arrayList1 again\n";
	arrayList1.addAll(arrayList2);
	PrintAllElement(arrayList1, "arrayList1");
	std::cout << "Retain all element from arrayList2 in arrayList1\n";
	arrayList1.retainAll(arrayList2);
	std::cout << "Current size: " << arrayList1.size() << "\n";
	PrintAllElement(arrayList1, "arrayList1");

	// test iterator
	auto it = arrayList1.iterator();

	try
	{
		std::cout << "Iterator has next element: " << it.hasNext() << "\n";
		std::cout << "Next element value: " << it.next() << "\n";
		std::cout << "Next element value: " << it.next() << "\n";
		std::cout << "Next element value: " << it.next() << "\n";
		std::cout << "Remove last element\n";
		it.remove();
		PrintAllElement(arrayList1, "arrayList1");
		std::cout << "Next element value: " << it.next() << "\n";

	} catch (const std::exception& e)
	{
		auto what = e.what();
		std::cout << "Exception is thrown: " << what << "\n";
	}

	std::cout << "************************************************************************************\n";

}

void TestArrayListWithSetString()
{
	std::cout << "TEST ARRAYLIST WITH SET<STRING>: \n";

	myCollection::HashSet<std::string, std::list<std::string>> arrayList1;

	arrayList1.add("four");
	arrayList1.add("years");
	arrayList1.add("no");
	arrayList1.add("call");
	arrayList1.add("from");
	arrayList1.add("you");


	PrintAllElement(arrayList1, "arrayList1");

	std::string elementToRemove{ "call" };
	std::cout << std::boolalpha << "Is arrayList1 empty: " << arrayList1.isEmpty() << "\n";
	std::cout << "Current size: " << arrayList1.size() << "\n";
	PrintAllElement(arrayList1, "arrayList1");

	std::cout << "Remove element with value: " << elementToRemove << "\n";

	arrayList1.remove(elementToRemove);

	std::cout << "Current size: " << arrayList1.size() << "\n";
	PrintAllElement(arrayList1, "arrayList1");

	myCollection::HashSet<std::string, std::list<std::string>> arrayList2{ "i","am","still", "waiting" };
	PrintAllElement(arrayList2, "arrayList2");
	std::cout << "Add arrayList2 to hashset 1 \n";
	arrayList1.addAll(arrayList2);

	std::cout << "Current size: " << arrayList1.size() << "\n";
	PrintAllElement(arrayList1, "arrayList1");

	std::string elementToCheck{ "hey" };
	std::cout << std::boolalpha << "arrayList1 contain element " << elementToCheck << " :" << arrayList1.contains(elementToCheck) << "\n";

	std::cout << "Remove all from arrayList1 with element from arrayList2\n";
	arrayList1.removeAll(arrayList2);
	std::cout << "Current size: " << arrayList1.size() << "\n";
	PrintAllElement(arrayList1, "arrayList1");

	// add it again to test retainAll function

	std::cout << "Add arrayList2 to arrayList1 again\n";
	arrayList1.addAll(arrayList2);
	PrintAllElement(arrayList1, "arrayList1");
	std::cout << "Retain all element from arrayList2 in arrayList1\n";
	arrayList1.retainAll(arrayList2);
	std::cout << "Current size: " << arrayList1.size() << "\n";
	PrintAllElement(arrayList1, "arrayList1");

	// test iterator
	auto it = arrayList1.iterator();

	try
	{
		std::cout << "Iterator has next element: " << it.hasNext() << "\n";
		std::cout << "Next element value: " << it.next() << "\n";
		std::cout << "Next element value: " << it.next() << "\n";
		std::cout << "Next element value: " << it.next() << "\n";
		std::cout << "Remove last element\n";
		it.remove();
		std::cout << "Iterator has next element: " << it.hasNext() << "\n";
		PrintAllElement(arrayList1, "arrayList1");
		std::cout << "Next element value: " << it.next() << "\n";

	} catch (const std::exception& e)
	{
		auto what = e.what();
		std::cout << "Exception is thrown: " << what << "\n";
	}

	std::cout << "************************************************************************************\n";
}


//**************************************************LinkedList*********************************************

void TestLinkedListWithVectorInt()
{
	std::cout << "TEST LINKEDLIST WITH VECTOR<INT>: \n";

	myCollection::LinkedList<int> linkedList1;

	linkedList1.add(1);
	linkedList1.add(2);
	linkedList1.add(5);
	linkedList1.add(10);
	linkedList1.add(15);
	linkedList1.add(20);

	PrintAllElement(linkedList1, "linkedList1");

	int elementToRemove = 15;
	std::cout << std::boolalpha << "Is linkedList1 empty: " << linkedList1.isEmpty() << "\n";
	std::cout << "Current size: " << linkedList1.size() << "\n";
	PrintAllElement(linkedList1, "linkedList1");

	std::cout << "Remove element with value: " << elementToRemove << "\n";

	linkedList1.remove(elementToRemove);

	std::cout << "Current size: " << linkedList1.size() << "\n";
	PrintAllElement(linkedList1, "linkedList1");

	myCollection::LinkedList<int> linkedList2{ 25,30,34,65 };
	PrintAllElement(linkedList2, "linkedList2");
	std::cout << "Add linkedList2 to linkedList1 \n";
	linkedList1.addAll(linkedList2);

	std::cout << "Current size: " << linkedList1.size() << "\n";
	PrintAllElement(linkedList1, "linkedList1");

	int elementToCheck = 34;
	std::cout << std::boolalpha << "linkedList1 contain element " << elementToCheck << " :" << linkedList1.contains(elementToCheck) << "\n";

	std::cout << "Remove all from linkedList1 with element from linkedList2\n";
	linkedList1.removeAll(linkedList2);
	std::cout << "Current size: " << linkedList1.size() << "\n";
	PrintAllElement(linkedList1, "linkedList1");

	// add it again to test retainAll function

	std::cout << "Add linkedList2 to linkedList1 again\n";
	linkedList1.addAll(linkedList2);
	PrintAllElement(linkedList1, "linkedList1");
	std::cout << "Retain all element from linkedList2 in linkedList1\n";
	linkedList1.retainAll(linkedList2);
	std::cout << "Current size: " << linkedList1.size() << "\n";
	PrintAllElement(linkedList1, "linkedList1");

	std::cout << "Retrieve the head element: " << linkedList1.element() << "\n";
	int elemToInsert = 105;
	std::cout << "Insert element with value: "<< elemToInsert << " using offer function\n";
	linkedList1.offer(elemToInsert);
	std::cout << "Current size: " << linkedList1.size() << "\n";
	PrintAllElement(linkedList1, "linkedList1");
	std::cout << "Retrieves and removes the head element: " << linkedList1.poll() << "\n";

	std::cout << "Current size: " << linkedList1.size() << "\n";
	PrintAllElement(linkedList1, "linkedList1");

	// test iterator
	auto it = linkedList1.iterator();

	try
	{
		std::cout << "Iterator has next element: " << it.hasNext() << "\n";
		std::cout << "Next element value: " << it.next() << "\n";
		std::cout << "Next element value: " << it.next() << "\n";
		std::cout << "Next element value: " << it.next() << "\n";
		std::cout << "Remove last element\n";
		it.remove();
		PrintAllElement(linkedList1, "linkedList1");
		std::cout << "Next element value: " << it.next() << "\n";

	} catch (const std::exception& e)
	{
		auto what = e.what();
		std::cout << "Exception is thrown: " << what << "\n";
	}
	
	try
	{

		std::cout << "Clear the linked list\n";
		linkedList1.clear();

		std::cout << "Current size: " << linkedList1.size() << "\n";
		PrintAllElement(linkedList1, "linkedList1");

		std::cout << "Try to retrive the head element using poll()\n";
		auto headVal = linkedList1.poll();

	} catch (const std::exception& e)
	{
		auto what = e.what();
		std::cout << "Exception is thrown: " << what << "\n";
	}

	std::cout << "************************************************************************************\n";
}

void TestLinkedListWithVectorString()
{
	std::cout << "TEST LINKEDLIST WITH VECTOR<STRING>: \n";

	myCollection::LinkedList<std::string> linkedList1;

	linkedList1.add("four");
	linkedList1.add("years");
	linkedList1.add("no");
	linkedList1.add("call");
	linkedList1.add("from");
	linkedList1.add("you");


	PrintAllElement(linkedList1, "linkedList1");

	std::string elementToRemove{ "call" };
	std::cout << std::boolalpha << "Is linkedList1 empty: " << linkedList1.isEmpty() << "\n";
	std::cout << "Current size: " << linkedList1.size() << "\n";
	PrintAllElement(linkedList1, "linkedList1");

	std::cout << "Remove element with value: " << elementToRemove << "\n";

	linkedList1.remove(elementToRemove);

	std::cout << "Current size: " << linkedList1.size() << "\n";
	PrintAllElement(linkedList1, "linkedList1");

	myCollection::LinkedList<std::string> linkedList2{ "i","am","still", "waiting" };
	PrintAllElement(linkedList2, "linkedList2");
	std::cout << "Add linkedList2 to hashset 1 \n";
	linkedList1.addAll(linkedList2);

	std::cout << "Current size: " << linkedList1.size() << "\n";
	PrintAllElement(linkedList1, "linkedList1");

	std::string elementToCheck{ "ya" };
	std::cout << std::boolalpha << "linkedList1 contain element " << elementToCheck << " :" << linkedList1.contains(elementToCheck) << "\n";

	std::cout << "Remove all from linkedList1 with element from linkedList2\n";
	linkedList1.removeAll(linkedList2);
	std::cout << "Current size: " << linkedList1.size() << "\n";
	PrintAllElement(linkedList1, "linkedList1");

	// add it again to test retainAll function

	std::cout << "Add linkedList2 to linkedList1 again\n";
	linkedList1.addAll(linkedList2);
	PrintAllElement(linkedList1, "linkedList1");
	std::cout << "Retain all element from linkedList2 in linkedList1\n";
	linkedList1.retainAll(linkedList2);
	std::cout << "Current size: " << linkedList1.size() << "\n";
	PrintAllElement(linkedList1, "linkedList1");

	std::cout << "Retrieve the head element: " << linkedList1.element() << "\n";
	std::string elemToInsert{ "gift" };
	std::cout << "Insert element with value: " << elemToInsert << " using offer function\n";
	linkedList1.offer(elemToInsert);
	std::cout << "Current size: " << linkedList1.size() << "\n";
	PrintAllElement(linkedList1, "linkedList1");
	std::cout << "Retrieves and removes the head element: " << linkedList1.poll() << "\n";

	std::cout << "Current size: " << linkedList1.size() << "\n";
	PrintAllElement(linkedList1, "linkedList1");

	// test iterator
	auto it = linkedList1.iterator();

	try
	{
		std::cout << "Iterator has next element: " << it.hasNext() << "\n";
		std::cout << "Next element value: " << it.next() << "\n";
		std::cout << "Next element value: " << it.next() << "\n";
		std::cout << "Next element value: " << it.next() << "\n";
		std::cout << "Remove last element\n";
		it.remove();
		std::cout << "Iterator has next element: " << it.hasNext() << "\n";
		PrintAllElement(linkedList1, "linkedList1");
		std::cout << "Next element value: " << it.next() << "\n";

	} catch (const std::exception& e)
	{
		auto what = e.what();
		std::cout << "Exception is thrown: " << what << "\n";
	}

	try
	{

		std::cout << "Clear the linkedList1\n";
		linkedList1.clear();

		std::cout << "Current size: " << linkedList1.size() << "\n";
		PrintAllElement(linkedList1, "linkedList1");

		std::cout << "Try to retrive the head element using poll()\n";
		auto headVal = linkedList1.poll();

	} catch (const std::exception& e)
	{
		auto what = e.what();
		std::cout << "Exception is thrown: " << what << "\n";
	}

	std::cout << "************************************************************************************\n";
}

void TestLinkedListWithListInt()
{
	std::cout << "TEST LINKEDLIST WITH LIST<INT>: \n";

	myCollection::LinkedList<int, std::list<int>> linkedList1;

	linkedList1.add(1);
	linkedList1.add(2);
	linkedList1.add(5);
	linkedList1.add(10);
	linkedList1.add(15);
	linkedList1.add(20);

	PrintAllElement(linkedList1, "linkedList1");

	int elementToRemove = 15;
	std::cout << std::boolalpha << "Is linkedList1 empty: " << linkedList1.isEmpty() << "\n";
	std::cout << "Current size: " << linkedList1.size() << "\n";
	PrintAllElement(linkedList1, "linkedList1");

	std::cout << "Remove element with value: " << elementToRemove << "\n";

	linkedList1.remove(elementToRemove);

	std::cout << "Current size: " << linkedList1.size() << "\n";
	PrintAllElement(linkedList1, "linkedList1");

	myCollection::LinkedList<int, std::list<int>> linkedList2{ 25,30,34,65 };
	PrintAllElement(linkedList2, "linkedList2");
	std::cout << "Add linkedList2 to linkedList1 \n";
	linkedList1.addAll(linkedList2);

	std::cout << "Current size: " << linkedList1.size() << "\n";
	PrintAllElement(linkedList1, "linkedList1");

	int elementToCheck = 34;
	std::cout << std::boolalpha << "linkedList1 contain element " << elementToCheck << " :" << linkedList1.contains(elementToCheck) << "\n";

	std::cout << "Remove all from linkedList1 with element from linkedList2\n";
	linkedList1.removeAll(linkedList2);
	std::cout << "Current size: " << linkedList1.size() << "\n";
	PrintAllElement(linkedList1, "linkedList1");

	// add it again to test retainAll function

	std::cout << "Add linkedList2 to linkedList1 again\n";
	linkedList1.addAll(linkedList2);
	PrintAllElement(linkedList1, "linkedList1");
	std::cout << "Retain all element from linkedList2 in linkedList1\n";
	linkedList1.retainAll(linkedList2);
	std::cout << "Current size: " << linkedList1.size() << "\n";
	PrintAllElement(linkedList1, "linkedList1");

	std::cout << "Retrieve the head element: " << linkedList1.element() << "\n";
	int elemToInsert = 105;
	std::cout << "Insert element with value: " << elemToInsert << " using offer function\n";
	linkedList1.offer(elemToInsert);
	std::cout << "Current size: " << linkedList1.size() << "\n";
	PrintAllElement(linkedList1, "linkedList1");
	std::cout << "Retrieves and removes the head element: " << linkedList1.poll() << "\n";

	std::cout << "Current size: " << linkedList1.size() << "\n";
	PrintAllElement(linkedList1, "linkedList1");

	// test iterator
	auto it = linkedList1.iterator();

	try
	{
		std::cout << "Iterator has next element: " << it.hasNext() << "\n";
		std::cout << "Next element value: " << it.next() << "\n";
		std::cout << "Next element value: " << it.next() << "\n";
		std::cout << "Next element value: " << it.next() << "\n";
		std::cout << "Remove last element\n";
		it.remove();
		PrintAllElement(linkedList1, "linkedList1");
		std::cout << "Next element value: " << it.next() << "\n";

	} catch (const std::exception& e)
	{
		auto what = e.what();
		std::cout << "Exception is thrown: " << what << "\n";
	}

	try
	{

		std::cout << "Clear the linked list\n";
		linkedList1.clear();

		std::cout << "Current size: " << linkedList1.size() << "\n";
		PrintAllElement(linkedList1, "linkedList1");

		std::cout << "Try to retrive the head element using poll()\n";
		auto headVal = linkedList1.poll();

	} catch (const std::exception& e)
	{
		auto what = e.what();
		std::cout << "Exception is thrown: " << what << "\n";
	}

	std::cout << "************************************************************************************\n";
}

void TestLinkedListWithListString()
{
	std::cout << "TEST LINKEDLIST WITH LIST<STRING>: \n";

	myCollection::LinkedList<std::string, std::list<std::string>> linkedList1;

	linkedList1.add("four");
	linkedList1.add("years");
	linkedList1.add("no");
	linkedList1.add("call");
	linkedList1.add("from");
	linkedList1.add("you");


	PrintAllElement(linkedList1, "linkedList1");

	std::string elementToRemove{ "call" };
	std::cout << std::boolalpha << "Is linkedList1 empty: " << linkedList1.isEmpty() << "\n";
	std::cout << "Current size: " << linkedList1.size() << "\n";
	PrintAllElement(linkedList1, "linkedList1");

	std::cout << "Remove element with value: " << elementToRemove << "\n";

	linkedList1.remove(elementToRemove);

	std::cout << "Current size: " << linkedList1.size() << "\n";
	PrintAllElement(linkedList1, "linkedList1");

	myCollection::LinkedList<std::string, std::list<std::string>> linkedList2{ "i","am","still", "waiting" };
	PrintAllElement(linkedList2, "linkedList2");
	std::cout << "Add linkedList2 to hashset 1 \n";
	linkedList1.addAll(linkedList2);

	std::cout << "Current size: " << linkedList1.size() << "\n";
	PrintAllElement(linkedList1, "linkedList1");

	std::string elementToCheck{ "hey" };
	std::cout << std::boolalpha << "linkedList1 contain element " << elementToCheck << " :" << linkedList1.contains(elementToCheck) << "\n";

	std::cout << "Remove all from linkedList1 with element from linkedList2\n";
	linkedList1.removeAll(linkedList2);
	std::cout << "Current size: " << linkedList1.size() << "\n";
	PrintAllElement(linkedList1, "linkedList1");

	// add it again to test retainAll function

	std::cout << "Add linkedList2 to linkedList1 again\n";
	linkedList1.addAll(linkedList2);
	PrintAllElement(linkedList1, "linkedList1");
	std::cout << "Retain all element from linkedList2 in linkedList1\n";
	linkedList1.retainAll(linkedList2);
	std::cout << "Current size: " << linkedList1.size() << "\n";
	PrintAllElement(linkedList1, "linkedList1");

	std::cout << "Retrieve the head element: " << linkedList1.element() << "\n";
	std::string elemToInsert{ "gift" };
	std::cout << "Insert element with value: " << elemToInsert << " using offer function\n";
	linkedList1.offer(elemToInsert);
	std::cout << "Current size: " << linkedList1.size() << "\n";
	PrintAllElement(linkedList1, "linkedList1");
	std::cout << "Retrieves and removes the head element: " << linkedList1.poll() << "\n";

	std::cout << "Current size: " << linkedList1.size() << "\n";
	PrintAllElement(linkedList1, "linkedList1");

	// test iterator
	auto it = linkedList1.iterator();

	try
	{
		std::cout << "Iterator has next element: " << it.hasNext() << "\n";
		std::cout << "Next element value: " << it.next() << "\n";
		std::cout << "Next element value: " << it.next() << "\n";
		std::cout << "Next element value: " << it.next() << "\n";
		std::cout << "Remove last element\n";
		it.remove();
		std::cout << "Iterator has next element: " << it.hasNext() << "\n";
		PrintAllElement(linkedList1, "linkedList1");
		std::cout << "Next element value: " << it.next() << "\n";

	} catch (const std::exception& e)
	{
		auto what = e.what();
		std::cout << "Exception is thrown: " << what << "\n";
	}

	try
	{

		std::cout << "Clear the linkedList1\n";
		linkedList1.clear();

		std::cout << "Current size: " << linkedList1.size() << "\n";
		PrintAllElement(linkedList1, "linkedList1");

		std::cout << "Try to retrive the head element using poll()\n";
		auto headVal = linkedList1.poll();

	} catch (const std::exception& e)
	{
		auto what = e.what();
		std::cout << "Exception is thrown: " << what << "\n";
	}

	std::cout << "************************************************************************************\n";
}

void TestLinkedListWithSetInt()
{
	std::cout << "TEST LINKEDLIST WITH SET<INT>: \n";

	myCollection::LinkedList<int, std::set<int>> linkedList1;

	linkedList1.add(1);
	linkedList1.add(2);
	linkedList1.add(5);
	linkedList1.add(10);
	linkedList1.add(15);
	linkedList1.add(20);

	PrintAllElement(linkedList1, "linkedList1");

	int elementToRemove = 15;
	std::cout << std::boolalpha << "Is linkedList1 empty: " << linkedList1.isEmpty() << "\n";
	std::cout << "Current size: " << linkedList1.size() << "\n";
	PrintAllElement(linkedList1, "linkedList1");

	std::cout << "Remove element with value: " << elementToRemove << "\n";

	linkedList1.remove(elementToRemove);

	std::cout << "Current size: " << linkedList1.size() << "\n";
	PrintAllElement(linkedList1, "linkedList1");

	myCollection::LinkedList<int, std::set<int>> linkedList2{ 25,30,34,65 };
	PrintAllElement(linkedList2, "linkedList2");
	std::cout << "Add linkedList2 to linkedList1 \n";
	linkedList1.addAll(linkedList2);

	std::cout << "Current size: " << linkedList1.size() << "\n";
	PrintAllElement(linkedList1, "linkedList1");

	int elementToCheck = 34;
	std::cout << std::boolalpha << "linkedList1 contain element " << elementToCheck << " :" << linkedList1.contains(elementToCheck) << "\n";

	std::cout << "Remove all from linkedList1 with element from linkedList2\n";
	linkedList1.removeAll(linkedList2);
	std::cout << "Current size: " << linkedList1.size() << "\n";
	PrintAllElement(linkedList1, "linkedList1");

	// add it again to test retainAll function

	std::cout << "Add linkedList2 to linkedList1 again\n";
	linkedList1.addAll(linkedList2);
	PrintAllElement(linkedList1, "linkedList1");
	std::cout << "Retain all element from linkedList2 in linkedList1\n";
	linkedList1.retainAll(linkedList2);
	std::cout << "Current size: " << linkedList1.size() << "\n";
	PrintAllElement(linkedList1, "linkedList1");

	std::cout << "Retrieve the head element: " << linkedList1.element() << "\n";
	int elemToInsert = 105;
	std::cout << "Insert element with value: " << elemToInsert << " using offer function\n";
	linkedList1.offer(elemToInsert);
	std::cout << "Current size: " << linkedList1.size() << "\n";
	PrintAllElement(linkedList1, "linkedList1");
	std::cout << "Retrieves and removes the head element: " << linkedList1.poll() << "\n";

	std::cout << "Current size: " << linkedList1.size() << "\n";
	PrintAllElement(linkedList1, "linkedList1");

	// test iterator
	auto it = linkedList1.iterator();

	try
	{
		std::cout << "Iterator has next element: " << it.hasNext() << "\n";
		std::cout << "Next element value: " << it.next() << "\n";
		std::cout << "Next element value: " << it.next() << "\n";
		std::cout << "Next element value: " << it.next() << "\n";
		std::cout << "Remove last element\n";
		it.remove();
		PrintAllElement(linkedList1, "linkedList1");
		std::cout << "Next element value: " << it.next() << "\n";

	} catch (const std::exception& e)
	{
		auto what = e.what();
		std::cout << "Exception is thrown: " << what << "\n";
	}

	try
	{

		std::cout << "Clear the linked list\n";
		linkedList1.clear();

		std::cout << "Current size: " << linkedList1.size() << "\n";
		PrintAllElement(linkedList1, "linkedList1");

		std::cout << "Try to retrive the head element using poll()\n";
		auto headVal = linkedList1.poll();

	} catch (const std::exception& e)
	{
		auto what = e.what();
		std::cout << "Exception is thrown: " << what << "\n";
	}

	std::cout << "************************************************************************************\n";
}

void TestLinkedListWithSetString()
{
	std::cout << "TEST LINKEDLIST WITH SET<STRING>: \n";

	myCollection::LinkedList<std::string, std::set<std::string>> linkedList1;

	linkedList1.add("four");
	linkedList1.add("years");
	linkedList1.add("no");
	linkedList1.add("call");
	linkedList1.add("from");
	linkedList1.add("you");


	PrintAllElement(linkedList1, "linkedList1");

	std::string elementToRemove{ "call" };
	std::cout << std::boolalpha << "Is linkedList1 empty: " << linkedList1.isEmpty() << "\n";
	std::cout << "Current size: " << linkedList1.size() << "\n";
	PrintAllElement(linkedList1, "linkedList1");

	std::cout << "Remove element with value: " << elementToRemove << "\n";

	linkedList1.remove(elementToRemove);

	std::cout << "Current size: " << linkedList1.size() << "\n";
	PrintAllElement(linkedList1, "linkedList1");

	myCollection::LinkedList<std::string, std::set<std::string>> linkedList2{ "i","am","still", "waiting" };
	PrintAllElement(linkedList2, "linkedList2");
	std::cout << "Add linkedList2 to hashset 1 \n";
	linkedList1.addAll(linkedList2);

	std::cout << "Current size: " << linkedList1.size() << "\n";
	PrintAllElement(linkedList1, "linkedList1");

	std::string elementToCheck{ "hey" };
	std::cout << std::boolalpha << "linkedList1 contain element " << elementToCheck << " :" << linkedList1.contains(elementToCheck) << "\n";

	std::cout << "Remove all from linkedList1 with element from linkedList2\n";
	linkedList1.removeAll(linkedList2);
	std::cout << "Current size: " << linkedList1.size() << "\n";
	PrintAllElement(linkedList1, "linkedList1");

	// add it again to test retainAll function

	std::cout << "Add linkedList2 to linkedList1 again\n";
	linkedList1.addAll(linkedList2);
	PrintAllElement(linkedList1, "linkedList1");
	std::cout << "Retain all element from linkedList2 in linkedList1\n";
	linkedList1.retainAll(linkedList2);
	std::cout << "Current size: " << linkedList1.size() << "\n";
	PrintAllElement(linkedList1, "linkedList1");

	std::cout << "Retrieve the head element: " << linkedList1.element() << "\n";
	std::string elemToInsert{ "gift" };
	std::cout << "Insert element with value: " << elemToInsert << " using offer function\n";
	linkedList1.offer(elemToInsert);
	std::cout << "Current size: " << linkedList1.size() << "\n";
	PrintAllElement(linkedList1, "linkedList1");
	std::cout << "Retrieves and removes the head element: " << linkedList1.poll() << "\n";

	std::cout << "Current size: " << linkedList1.size() << "\n";
	PrintAllElement(linkedList1, "linkedList1");

	// test iterator
	auto it = linkedList1.iterator();

	try
	{
		std::cout << "Iterator has next element: " << it.hasNext() << "\n";
		std::cout << "Next element value: " << it.next() << "\n";
		std::cout << "Next element value: " << it.next() << "\n";
		std::cout << "Next element value: " << it.next() << "\n";
		std::cout << "Remove last element\n";
		it.remove();
		std::cout << "Iterator has next element: " << it.hasNext() << "\n";
		PrintAllElement(linkedList1, "linkedList1");
		std::cout << "Next element value: " << it.next() << "\n";

	} catch (const std::exception& e)
	{
		auto what = e.what();
		std::cout << "Exception is thrown: " << what << "\n";
	}

	try
	{

		std::cout << "Clear the linkedList1\n";
		linkedList1.clear();

		std::cout << "Current size: " << linkedList1.size() << "\n";
		PrintAllElement(linkedList1, "linkedList1");

		std::cout << "Try to retrive the head element using poll()\n";
		auto headVal = linkedList1.poll();

	} catch (const std::exception& e)
	{
		auto what = e.what();
		std::cout << "Exception is thrown: " << what << "\n";
	}

	std::cout << "************************************************************************************\n";
}


int main() {

	// Test HashSet
	TestHashSetWithVectorInt();
	TestHashSetWithVectorString();
	TestHashSetWithListInt();
	TestHashSetWithListString();
	TestHashSetWithSetInt();
	TestHashSetWithSetString();

	// Test ArrayList
	TestArrayListWithVectorInt();
	TestArrayListWithVectorString();
	TestArrayListWithListInt();
	TestArrayListWithListString();
	TestArrayListWithSetInt();
	TestArrayListWithSetString();

	// Test LinkedList
	TestLinkedListWithVectorInt();
	TestLinkedListWithVectorString();
	TestLinkedListWithListInt();
	TestLinkedListWithListString();
	TestLinkedListWithSetInt();
}
