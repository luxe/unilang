//Trevor Hickey
//Dan Bennett
//05/05/11
//Linked List Header File

#ifndef LIST_H
#define LIST_H

#include "student.h"
#include <string>


using std::string;
typedef StudentT ItemT;

class ListT{
	
public:
	//╔══════════════════════╗
	//║     Constructors     ║
	//╚══════════════════════╝
	
	ListT();
	//creates an empty linked list
	
	ListT(const ListT & list);
	//copy constructor
	
	//╔══════════════════════╗
	//║      Observers       ║
	//╚══════════════════════╝
	
	int Size(); 
	//Return the number of elements in the list.
	
	bool IsPresent(const string & key); 
	//returns true if key is in the list.
	
	ItemT Get(const string & key);
	//returns the item matching key.
	//*if there is no match, the function returns a default ItemT
	
	ItemT GetIndex();
	//returns the value pointed to by the internal index.
	
	bool ValidIndex();
	//returns true if the index is not pointing to NULL.
	
	bool IsLast();
	//returns true if the internal index is pointing to the last item in the list.
	
	string Key();
	//returns the key of the item that the index is pointing to
	
	//╔══════════════════════╗
	//║     Transformers     ║
	//╚══════════════════════╝
	
	void Delete(const string & key);
	//deletes all occurrences of key in the list
	
	void Insert(const ItemT & item);
	//inserts item into the list
	
	void ResetIndex();
	//Set the internal index to the first item in the list
	
	void NextItem();
	//move the internal index to the next item in the list. This will not advance past the last item in the list.
	
	void PrintList();
	//print the list item by item starting at the head and ending once NULL is reached
	
	//╔══════════════════════╗
	//║      Destructor      ║
	//╚══════════════════════╝
	
	~ListT();
	//properly handles the destruction of the linked list class by avoiding memory leaks
	
	//╔══════════════════════╗
	//║   Debugging Tools    ║
	//╚══════════════════════╝
	
protected:
	
private:
	
	ItemT *head;
	ItemT *tail;
	ItemT *index;
	int size;
	
};
#endif