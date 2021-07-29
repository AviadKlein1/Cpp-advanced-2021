#pragma once
#include<iostream>
using namespace std;
//------------------------------------------------
//  class List
//      arbitrary size Lists
//      permits insertion and removal 
//      only from the front of the List
//------------------------------------------------
class List
{
protected:
	//--------------------------------------------
	//  inner class link
	//  a single element for the linked List 
	//--------------------------------------------
	class Link
	{
	public:

		// data areas
		int value;
		Link* next;
		// constructor
		Link(int linkValue, Link* nextPtr);
		Link(const Link&);
	};	//end of class Link
public:
	// constructors
	List();
	List(const List&);
	~List();

	// operations
	void add(int value);
	int firstElement() const;
	bool search(const int& value) const;
	bool isEmpty() const;
	void removeFirst();
	void clear();

	void insert(int key);
	void remove(int key);
	friend ostream& operator<<(ostream& os, List& l);
	friend istream& operator>>(istream& is, List& l);
	List operator=(const List& l);


	void bbInsert(int key, List::Link* p);
	void bbRemove(int key, List::Link* p);

	void help_oper(List::Link* l1, List::Link* l2);
	void helpMerge(List l2);
	void helpMakeSet();
	List helpReverse(List);	

protected:
	// data field
	Link* head;
};
