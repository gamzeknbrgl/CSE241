//package mycollection;

public class Main {

	public static void main(String[] args) {

		TestArrayListString();
		TestArrayListInt();
		TestHashSetInt();
		TestHashSetString();
		TestLinkedListInt();
		TestLinkedListString();
	}

	static void TestArrayListString() {

		ArrayList<String> arr1 = new ArrayList<String>();
		ArrayList<String> arr2 = new ArrayList<String>();
		ArrayList<String> arr3 = new ArrayList<String>();

		try {

			arr1.add("Lorem");
			arr1.add("ipsum");
			arr1.add("dolor");
			arr1.add("dolor");
			arr1.add("dolor");
			arr1.add("sit");
			arr1.add("amet");
			arr1.add("consectetur");
			arr1.add("adipiscing");
			arr1.add("elit");
			arr1.add("Fusce");
			arr1.add("Fusce");
			arr1.add("Fusce");
			arr1.add("eget");
			arr1.add("velit");
			arr1.add("blandit");

			arr2.add("ipsum");
			arr2.add("porttitor");
			arr2.add("auctor");
			arr2.add("lacinia");
			arr2.add("lacinia");
			arr2.add("lacinia");
			arr2.add("finibus ");

			arr3.add("consectetur");
			arr3.add("adipiscing");
			arr3.add("elit");
			arr3.add("Fusce");

			System.out.println("Array1: " + arr1.toString());
			System.out.println("Array2: " + arr2.toString());
			System.out.println("Array3: " + arr3.toString());

			System.out.println("Does Array1 empty: " + arr1.isEmpty());

			System.out.println("Does Array1 contain Array2: " + arr1.containAll(arr2));
			System.out.println("Does Array1 contain Array3: " + arr1.containAll(arr3));

			System.out.println("Add Array2 to Array1");

			arr1.addAll(arr2);
			System.out.println("Array1: " + arr1.toString());

			System.out.println("Does Array1 contain element with value 'Lorem': " + arr1.contains("Lorem"));

			System.out.println("Remove element with value 'Lorem' from Array1");
			arr1.remove("Lorem");
			System.out.println("Array1: " + arr1.toString());

			System.out.println("Remove all element of Array 2 from Array 1");
			arr1.removeAll(arr2);
			System.out.println("Array1: " + arr1.toString());

			System.out.println("Retain all element of Array 3 from Array 1");
			arr1.retainAll(arr3);
			System.out.println("Array1: " + arr1.toString());

			System.out.println("**********Test iterator**********");
			MyIterator<String> myIterator = arr1.getMyIterator();

			System.out.println("Does my iterator has next: " + myIterator.hasNext());
			System.out.println("Next element value is: " + myIterator.next());
			System.out.println("Next element value is: " + myIterator.next());
			System.out.println("Next element value is: " + myIterator.next());

			System.out.println("Remove last element using MyIterator.remove()");
			myIterator.remove();
			System.out.println("Array1: " + arr1.toString());
			
			System.out.println("Clear the Array1");
			arr1.clear();
			System.out.println("Array1: " + arr1.toString());

		} catch (Exception e) {
			System.out.println("Error occurs: " + e.getMessage());
		}

		System.out.println("***********************************************");
	}

	static void TestArrayListInt() {

		ArrayList<Integer> arr1 = new ArrayList<Integer>();
		ArrayList<Integer> arr2 = new ArrayList<Integer>();
		ArrayList<Integer> arr3 = new ArrayList<Integer>();
		try {

			arr1.add(1);
			arr1.add(5);
			arr1.add(7);
			arr1.add(15);
			arr1.add(55);
			arr1.add(125);
			arr1.add(30);
			arr1.add(305);
			arr1.add(205);
			arr1.add(45);
			arr1.add(55);
			arr1.add(1024);

			arr2.add(1);
			arr2.add(5);
			arr2.add(70);
			arr2.add(155);
			arr2.add(55);

			arr3.add(7);
			arr3.add(15);
			arr3.add(55);
			arr3.add(125);

			System.out.println("Array1: " + arr1.toString());
			System.out.println("Array2: " + arr2.toString());
			System.out.println("Array3: " + arr3.toString());

			System.out.println("Does Array1 empty: " + arr1.isEmpty());

			System.out.println("Does Array1 contain Array2: " + arr1.containAll(arr2));
			System.out.println("Does Array1 contain Array3: " + arr1.containAll(arr3));

			System.out.println("Add Array2 to Array1");

			arr1.addAll(arr2);
			System.out.println("Array1: " + arr1.toString());

			System.out.println("Does Array1 contain element with value 125: " + arr1.contains(125));

			System.out.println("Remove element with value 305 from Array1");
			arr1.remove(305);
			System.out.println("Array1: " + arr1.toString());

			System.out.println("Remove all element of Array 2 from Array 1");
			arr1.removeAll(arr2);
			System.out.println("Array1: " + arr1.toString());

			System.out.println("Retain all element of Array 3 from Array 1");
			arr1.retainAll(arr3);
			System.out.println("Array1: " + arr1.toString());

			System.out.println("**********Test iterator**********");
			MyIterator<Integer> myIterator = arr1.getMyIterator();

			System.out.println("Does my iterator has next: " + myIterator.hasNext());
			System.out.println("Next element value is: " + myIterator.next());
			System.out.println("Next element value is: " + myIterator.next());
			System.out.println("Next element value is: " + myIterator.next());

			System.out.println("Remove last element using MyIterator.remove()");
			myIterator.remove();
			System.out.println("Array1: " + arr1.toString());
			
		} catch (Exception e) {
			System.out.println("Error occurs: " + e.getMessage());
		}
		
		System.out.println("***********************************************");
	}

	static void TestHashSetInt() {

		HashSet<Integer> arr1 = new HashSet<Integer>();
		HashSet<Integer> arr2 = new HashSet<Integer>();
		HashSet<Integer> arr3 = new HashSet<Integer>();

		try {
			arr1.add(1);
			arr1.add(5);
			arr1.add(7);
			arr1.add(15);
			arr1.add(55);
			arr1.add(125);
			arr1.add(125);
			arr1.add(30);
			arr1.add(305);
			arr1.add(305);
			arr1.add(205);
			arr1.add(45);
			arr1.add(55);
			arr1.add(1024);
			arr1.add(1024);
			arr1.add(1024);

			arr2.add(1);
			arr2.add(5);
			arr2.add(55);
			arr2.add(70);
			arr2.add(155);
			arr2.add(55);
			arr2.add(1024);

			arr3.add(7);
			arr3.add(15);
			arr3.add(55);
			arr3.add(125);

			System.out.println("HashSet1: " + arr1.toString());
			System.out.println("HashSet2: " + arr2.toString());
			System.out.println("HashSet3: " + arr3.toString());

			System.out.println("Does HashSet1 empty: " + arr1.isEmpty());

			System.out.println("Does HashSet1 contain HashSet2: " + arr1.containAll(arr2));
			System.out.println("Does HashSet1 contain HashSet3: " + arr1.containAll(arr3));

			System.out.println("Add HashSet2 to HashSet1");

			arr1.addAll(arr2);
			System.out.println("HashSet1: " + arr1.toString());

			System.out.println("Does HashSet1 contain element with value 125: " + arr1.contains(125));

			System.out.println("Remove element with value 305 from HashSet1");
			arr1.remove(305);
			System.out.println("HashSet1: " + arr1.toString());

			System.out.println("Remove all element of HashSet2 from HashSet1");
			arr1.removeAll(arr2);
			System.out.println("Array1: " + arr1.toString());

			System.out.println("Retain all element of HashSet3 from HashSet1");
			arr1.retainAll(arr3);
			System.out.println("HashSet1: " + arr1.toString());

			System.out.println("**********Test iterator**********");
			MyIterator<Integer> myIterator = arr1.getMyIterator();

			System.out.println("Does my iterator has next: " + myIterator.hasNext());
			System.out.println("Next element value is: " + myIterator.next());
			System.out.println("Next element value is: " + myIterator.next());
			System.out.println("Next element value is: " + myIterator.next());

			System.out.println("Remove last element using MyIterator.remove()");
			myIterator.remove();
			System.out.println("HashSet1: " + arr1.toString());

		} catch (Exception e) {
			System.out.println("Error occurs: " + e.getMessage());
		}
		
		System.out.println("***********************************************");
	}

	static void TestHashSetString() {

		HashSet<String> arr1 = new HashSet<String>();
		HashSet<String> arr2 = new HashSet<String>();
		HashSet<String> arr3 = new HashSet<String>();

		try {

			arr1.add("Lorem");
			arr1.add("ipsum");
			arr1.add("dolor");
			arr1.add("sit");
			arr1.add("amet");
			arr1.add("consectetur");
			arr1.add("adipiscing");
			arr1.add("elit");
			arr1.add("Fusce");
			arr1.add("eget");
			arr1.add("velit");
			arr1.add("blandit");

			arr2.add("ipsum");
			arr2.add("porttitor");
			arr2.add("auctor");
			arr2.add("lacinia");
			arr2.add("finibus ");

			arr3.add("consectetur");
			arr3.add("adipiscing");
			arr3.add("elit");
			arr3.add("Fusce");

			System.out.println("HashSet1: " + arr1.toString());
			System.out.println("HashSet2: " + arr2.toString());
			System.out.println("HashSet3: " + arr3.toString());

			System.out.println("Does HashSet1 empty: " + arr1.isEmpty());

			System.out.println("Does HashSet1 contain Array2: " + arr1.containAll(arr2));
			System.out.println("Does HashSet1 contain Array3: " + arr1.containAll(arr3));

			System.out.println("Add HashSet12 to HashSet1");

			arr1.addAll(arr2);
			System.out.println("HashSet1: " + arr1.toString());

			System.out.println("Does HashSet1 contain element with value 'Lorem': " + arr1.contains("Lorem"));

			System.out.println("Remove element with value 'Lorem' from HashSet1");
			arr1.remove("Lorem");
			System.out.println("Array1: " + arr1.toString());

			System.out.println("Remove all element of HashSet2 from HashSet1");
			arr1.removeAll(arr2);
			System.out.println("HashSet1: " + arr1.toString());

			System.out.println("Retain all element of HashSet3 from HashSet1");
			arr1.retainAll(arr3);
			System.out.println("HashSet1: " + arr1.toString());

			System.out.println("**********Test iterator**********");
			MyIterator<String> myIterator = arr1.getMyIterator();

			System.out.println("Does my iterator has next: " + myIterator.hasNext());
			System.out.println("Next element value is: " + myIterator.next());
			System.out.println("Next element value is: " + myIterator.next());
			System.out.println("Next element value is: " + myIterator.next());

			System.out.println("Remove last element using MyIterator.remove()");
			myIterator.remove();
			System.out.println("HashSet1: " + arr1.toString());

		} catch (Exception e) {
			System.out.println("Error occurs: " + e.getMessage());
		}
		
		System.out.println("***********************************************");
	}

	static void TestLinkedListInt() {

		LinkedList<Integer> arr1 = new LinkedList<Integer>();
		LinkedList<Integer> arr2 = new LinkedList<Integer>();
		LinkedList<Integer> arr3 = new LinkedList<Integer>();

		try {

			arr1.add(1);
			arr1.add(5);
			arr1.add(7);
			arr1.add(15);
			arr1.add(55);
			arr1.add(125);
			arr1.add(125);
			arr1.add(30);
			arr1.add(305);
			arr1.add(305);
			arr1.add(205);
			arr1.add(45);
			arr1.add(55);
			arr1.add(1024);
			arr1.add(1024);
			arr1.add(1024);

			arr2.add(1);
			arr2.add(5);
			arr2.add(55);
			arr2.add(70);
			arr2.add(155);
			arr2.add(55);
			arr2.add(1024);

			arr3.add(7);
			arr3.add(15);
			arr3.add(55);
			arr3.add(125);

			System.out.println("LinkedList1: " + arr1.toString());
			System.out.println("LinkedList2: " + arr2.toString());
			System.out.println("LinkedList3: " + arr3.toString());

			System.out.println("Does LinkedList1 empty: " + arr1.isEmpty());

			System.out.println("Does LinkedList1 contain LinkedList2: " + arr1.containAll(arr2));
			System.out.println("Does LinkedList1 contain LinkedList3: " + arr1.containAll(arr3));

			System.out.println("Add LinkedList2 to LinkedList1");

			arr1.addAll(arr2);
			System.out.println("Array1: " + arr1.toString());

			System.out.println("Does Array1 contain element with value 125: " + arr1.contains(125));

			System.out.println("Remove element with value 305 from Array1");
			arr1.remove(305);
			System.out.println("Array1: " + arr1.toString());

			System.out.println("Remove all element of LinkedList2 from LinkedList1");
			arr1.removeAll(arr2);
			System.out.println("Array1: " + arr1.toString());

			System.out.println("Retain all element of LinkedList3 from LinkedList1");
			arr1.retainAll(arr3);
			System.out.println("Array1: " + arr1.toString());

			System.out.println("Get LinkedList1 element at the head: " + arr1.element());

			System.out.println("**********Test iterator**********");
			MyIterator<Integer> myIterator = arr1.getMyIterator();

			System.out.println("Does my iterator has next: " + myIterator.hasNext());
			System.out.println("Next element value is: " + myIterator.next());
			System.out.println("Next element value is: " + myIterator.next());
			System.out.println("Next element value is: " + myIterator.next());

			System.out.println("Remove last element using MyIterator.remove()");
			myIterator.remove();
			System.out.println("LinkedList1: " + arr1.toString());

		} catch (Exception e) {
			System.out.println("Error occurs: " + e.getMessage());
		}
		
		System.out.println("***********************************************");
	}

	static void TestLinkedListString() {

		LinkedList<String> arr1 = new LinkedList<String>();
		LinkedList<String> arr2 = new LinkedList<String>();
		LinkedList<String> arr3 = new LinkedList<String>();

		try {

			arr1.add("Lorem");
			arr1.add("ipsum");
			arr1.add("dolor");
			arr1.add("sit");
			arr1.add("amet");
			arr1.add("consectetur");
			arr1.add("adipiscing");
			arr1.add("elit");
			arr1.add("Fusce");
			arr1.add("eget");
			arr1.add("velit");
			arr1.add("blandit");

			arr2.add("ipsum");
			arr2.add("porttitor");
			arr2.add("auctor");
			arr2.add("lacinia");
			arr2.add("finibus ");

			arr3.add("consectetur");
			arr3.add("adipiscing");
			arr3.add("elit");
			arr3.add("Fusce");

			System.out.println("LinkedList1: " + arr1.toString());
			System.out.println("LinkedList2: " + arr2.toString());
			System.out.println("LinkedList3: " + arr3.toString());

			System.out.println("Does LinkedList1 empty: " + arr1.isEmpty());

			System.out.println("Does LinkedList1 contain LinkedList2: " + arr1.containAll(arr2));
			System.out.println("Does LinkedList1 contain LinkedList3: " + arr1.containAll(arr3));

			System.out.println("Add LinkedList2 to LinkedList1");

			arr1.addAll(arr2);
			System.out.println("LinkedList1: " + arr1.toString());

			System.out.println("Does LinkedList1 contain element with value 'Lorem': " + arr1.contains("Lorem"));

			System.out.println("Remove element with value 'Lorem' from LinkedList1");
			arr1.remove("Lorem");
			System.out.println("LinkedList1: " + arr1.toString());

			System.out.println("Remove all element of LinkedList2 from LinkedList1");
			arr1.removeAll(arr2);
			System.out.println("LinkedList1: " + arr1.toString());

			System.out.println("Retain all element of LinkedList3 from LinkedList1");
			arr1.retainAll(arr3);
			System.out.println("LinkedList1: " + arr1.toString());

			System.out.println("**********Test iterator**********");
			MyIterator<String> myIterator = arr1.getMyIterator();

			System.out.println("Does my iterator has next: " + myIterator.hasNext());
			System.out.println("Next element value is: " + myIterator.next());
			System.out.println("Next element value is: " + myIterator.next());
			System.out.println("Next element value is: " + myIterator.next());

			System.out.println("Remove last element using MyIterator.remove()");
			myIterator.remove();
			System.out.println("LinkedList1: " + arr1.toString());
		} catch (Exception e) {
			System.out.println("Error occurs: " + e.getMessage());
		}
		
		System.out.println("***********************************************");
	}

}
