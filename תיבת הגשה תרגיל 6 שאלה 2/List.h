#pragma once
#include<iostream>
using namespace std;
class List
{
protected:

	class Link
	{
	public:
		int value;
		Link* next;

		Link(int linkvalue, Link* nextPtr);
		Link(const Link&);

	};

public:
	List();
	List(const List&);
	~List();

	int firstElement()const;
	bool isEmpty()const;
	void removeFirst();
	void clear();
	void reciOperator(List::Link* l1, List::Link* l2);
	List operator=(const List& l);
	


protected:
	Link* head;

};