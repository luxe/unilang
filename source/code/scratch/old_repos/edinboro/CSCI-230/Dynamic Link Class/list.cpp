//Trevor Hickey
//Dan Bennett
//05/05/11
//Linked List Implementation File

#include "list.h"
#include <iostream>

using std::cout;
using std::endl;

//╔══════════════════════╗
//║     Constructors     ║
//╚══════════════════════╝
ListT::ListT(){
	
	head = NULL;
	tail = NULL;
	index = head;
	size = 0;
	
	return;
}

 ListT::ListT(const ListT & list){
	
	index = head;
	size = 0;
	
	ItemT* temp;
	ItemT item;
	temp = list.head;
	item = *temp;
	head = new ItemT(item);
	
	temp = temp->next;
	
	while (temp != NULL)
	{
		item = *temp;
		Insert(item);
		temp = temp->next;
	}
	
	return;
}
//╔══════════════════════╗
//║      Observers       ║
//╚══════════════════════╝
int ListT::Size(){
	
	return size;
}

bool ListT::IsLast(){
	bool isLast = false;
	
	if (index->next == NULL){
		isLast = true;
	}

	return isLast;
}

bool ListT::ValidIndex(){
	bool validIndex = true;
	
	if (index == NULL){
		validIndex = false;
	}
	
	return validIndex;
}

ItemT ListT::GetIndex(){
	
	return *index;
}

void ListT::PrintList(){
	
	ItemT * tmp;
	
	for(tmp = head; tmp!= NULL; tmp=tmp->next) {
		cout << tmp->Key() << " " ;
	}
	cout << endl;
	
	return;
}

bool ListT::IsPresent(const string & key){
	bool itemFound = false;
	
	ItemT * tmp;
	
	for(tmp = head; tmp!= NULL && itemFound!= true; tmp = tmp -> next) {
		if (tmp->Key() == key) {
			itemFound = true;
		}
	}
	
	return itemFound;
}

ItemT ListT::Get(const string & key){
	bool itemFound = false;
	
	ItemT * tmp;
	
	for(tmp = head; tmp!= NULL && itemFound!= true; tmp = tmp -> next) {
		if (tmp->Key() == key) {
			itemFound = true;
		}
	}
	
	if (tmp != NULL){
		return *tmp;
	}
	else{
		return ItemT();
	}
}

//╔══════════════════════╗
//║     Transformers     ║
//╚══════════════════════╝

void ListT::Delete(const string & key){
	
	ItemT * current;
	ItemT * tail;
	
	if (head != NULL) {
		if (head->Key() == key) {
			current = head;
			head = head->next;
			delete current;
			size--;
		}
		else{
			current = head->next;
			tail = head;
			
			while (current != NULL && current->Key() != key) {
				current = current->next;
				tail = tail -> next;
			}
			
			if (current != NULL) {
				tail->next =  current->next;
				delete current;
				size--;
			}
		}
	}

	return;
}

void ListT::Insert(const ItemT & passedItem){
	
	ItemT item = passedItem; //creates a duplicate of the item passed in so that it's member functions may be called
	
	ItemT * tmp;       //temporary pointer for an ItemT
	tmp = new ItemT;   //create a new ItemT and point to it
	*tmp = item;       //set the new ItemT to the parameters data
	bool placementFound = false;
	
	ItemT * keySearcherFrontLink; //temporary pointers used to search the keys of ItemTs to see where to place the new one
	ItemT * keySearcherBackLink;  //*these make sure the Items are stored in alphabetical order
	
	//place the ItemT first if the head points to null or is less than the first item's key
	if ((head == NULL) || (item.Key() < head->Key())){
		tmp->next = head;  //set the newItemT's pointer to wherever the head pointer points to
		head = tmp;        //set the head to point to the newItemT
		                   //the item has been added to the list and the temporary pointer will go out of scope
	}
	else{
		keySearcherFrontLink = head;
		keySearcherBackLink = head->next;
		
		//continue advancing the two pointers until the spot is found where the new item belongs
		while (keySearcherBackLink != NULL && placementFound == false){
			if (keySearcherBackLink->Key() > tmp->Key()){
				placementFound = true;
			}
			else{
				keySearcherFrontLink = keySearcherFrontLink->next;
				keySearcherBackLink = keySearcherBackLink->next;
			}
		}

		//the item will be placed at the end of the list
		if (keySearcherBackLink == NULL){
			keySearcherFrontLink->next = tmp;
			tmp->next = NULL;
		}
		//the item will placed niether at the beginning nor the end of the list but somewhere inbetween
		else{
			keySearcherFrontLink->next = tmp;
			tmp->next = keySearcherBackLink;
		}
	}
	
	size++; //increment the size of the list
	return;
}

string ListT::Key(){
	
	ItemT student;
	student = GetIndex();
	
	return student.Key();
}
void ListT::NextItem(){
	
	if (index != NULL){
		index= index->next;
	}
	
	return;
}

void ListT::ResetIndex(){
	
	index = head;
	
	return;
}

//╔══════════════════════╗
//║      Destructor      ║
//╚══════════════════════╝

ListT::~ListT(){
	
	ItemT* tmp;
	
	for(tmp=head;tmp!=NULL;tmp = head) {
		if (tmp!= NULL){
		head=tmp->next;
		delete tmp;
		}
	}
	
	return;
}
