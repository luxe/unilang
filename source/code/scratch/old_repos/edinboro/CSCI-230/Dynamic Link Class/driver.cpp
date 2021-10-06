//Trevor Hickey
//Dan Bennett
//May 5, 2011
//Linked List Class Driver
/*This driver tests the linked list class by
	-intalizing an empty list
	-creating Items using various constructors
	-tests they Key function of each Item to ensure it is holding the correct value
	-Prints the empty list and makes sure it's size is zero
	-Inserts the items in a non alphabetical manner to test that they were stored alphabetically
	-Prints the list to see how they were stored and outputs the list size
	-checks the present function
	-tests the location of the index by performing the control structure found in the spec
	-deletes items and re-prints the list to test it's success
*/
	
#include <iostream>
#include <string>
#include "list.h"

using namespace std;

int main(){
	
	ListT list; //create a linked list type
	
	//test constructors
	ItemT test1;
	ItemT test2("a");
	ItemT test3("c");
	ItemT test4("b");
	ItemT test5(test1);
	ItemT test6 = test5;

	//test Key Function
	cout << test1.Key() << endl;         //NO_NAME
	cout << test2.Key() << endl;         //key2
	cout << test3.Key() << endl;         //key3
	cout << test4.Key() << endl;         //key4
	cout << test5.Key() << endl;         //NO_NAME
	cout << test6.Key() << endl << endl; //NO_NAME
	
	//test the contents and size of the list(should be empty and zero)
	list.PrintList();
	cout << list.Size() << endl << endl;

	//inset all the items
	list.Insert(test1); cout << endl;
	list.Insert(test2); cout << endl;
	list.Insert(test3); cout << endl;
	list.Insert(test4); cout << endl;
	list.Insert(test5); cout << endl;
	list.Insert(test6); cout << endl;
	
	//test the contents and size of the list(should contain 6 items in alphabetical order)
	list.PrintList();
	cout << list.Size() << endl << endl;
	
	//test IsPresent function
	cout << boolalpha;
	cout << list.IsPresent("key4")   << endl;         //true
	cout << list.IsPresent("NO_NAME")<< endl;         //true
	cout << list.IsPresent("sjdfkl") << endl;         //false
	cout << list.IsPresent("asdasd") << endl << endl; //false
	
	
	//test looping through from begginning to end of the linked list using the index
	for(list.ResetIndex();!list.IsLast();list.NextItem()) {
		cout <<  list.GetIndex() << endl;
	}
	if (list.ValidIndex()) {
		cout <<  list.GetIndex();
	}
	
	//test Delete function
	list.Delete("NO_NAME");
	list.PrintList();                    //list check
	cout << list.Size() << endl << endl; //size check
	
	return 0;
}