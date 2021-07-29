#include "List.h"

//------------------------------------------------
//  class Link implementation
//------------------------------------------------
List::Link::Link(int val, Link* nxt) : value(val), next(nxt)
{}
List::Link::Link(const Link& source) : value(source.value), next(source.next)
{}

//--------------------------------------------
//  class List implementation
//--------------------------------------------
List::List() : head(NULL)
{
	// no further initialization
}
List::List(const List& l)
{
	Link* src, * trg;
	if (l.head == NULL)
		head = NULL;
	else
	{
		head = new Link((l.head)->value, NULL);
		src = l.head;
		trg = head;
		while (src->next != NULL)
		{
			trg->next = new Link((src->next)->value, NULL);
			src = src->next;
			trg = trg->next;
		}
	}
}
List::~List()
{
	clear();
}

void List::clear()
{
	// empty all elements from the List
	Link* theNext;
	for (Link* p = head; p != NULL; p = theNext)
	{
		// delete the element pointed to by p
		theNext = p->next;
		p->next = NULL;
		delete p;
	}
	// mark that the List contains no elements
	head = NULL;
}
bool List::isEmpty() const
{
	// test to see if the List is empty
	// List is empty if the pointer to the head
	// Link is null
	return head == NULL;
}
void List::add(int val)
{
	//Add a new value to the front of a Linked List
	head = new Link(val, head);
	if (head == NULL)
		throw "failed in memory allocation";
}

int List::firstElement() const
{
	// return first value in List
	if (isEmpty())
		throw "the List is empty, no first Element";
	return head->value;
}
bool  List::search(const int& val) const
{
	// loop to test each element
	for (Link* p = head; p != NULL; p = p->next)
		if (val == p->value)
			return true;
	// not found
	return false;
}
void List::removeFirst()
{
	// make sure there is a first element
	if (isEmpty())
		throw "the List is empty, no Elements to remove";
	// save pointer to the removed node
	Link* p = head;
	// reassign the first node
	head = p->next;
	p->next = NULL;
	// recover memory used by the first element
	delete p;
}

void List::insert(int key)
{
	if (head == NULL)  //if the list is empty
		head = new Link(key, NULL);
	else if (key > head->value) //if the  key bigger than head value
		head = new Link(key, head);
	else
		bbInsert(key, head); // check where to put key (between or in the last)
}
void List::remove(int key) {
	Link* p = head;
	if (head == NULL)    //empty list
		return;
	if (head->value == key) {//in the start
		head = head->next;
		delete p;
		return;
	}
	bbRemove(key, head); //between the list
}
List List::operator=(const List& l) {
	clear();
	if (l.head == NULL) {  //empty list
		head = NULL;
		return *this;
	}
	head = new Link((l.head)->value, NULL);  //copy first link
	help_oper(l.head, head);
	return *this;
}
ostream& operator<<(ostream& os, List& l) {
	List::Link* p = l.head;
	while (p != NULL) {

		os << p->value << " ";
		p = p->next;
	}
	return os;
}
istream& operator>>(istream& is, List& l) {
	int big, small;
	is >> small;
	do {
		l.insert(small);
		big = small;
		cin >> small;
	} while (small < big);
	return is;
}


void List::bbRemove(int key, List::Link* p) {
	Link* k = p->next;
	if (k == NULL)   //empty list- value not found
		throw "value not found";
	if (k->value == key) { //found key and delete
		p->next = k->next;
		delete k;
		return;
	}
	bbRemove(key, p->next);
}
void List::bbInsert(int key, List::Link* p) {
	//last
	if (p->next == NULL) {
		p->next = new Link(key, NULL);
		return;
	}
	//between
	if (p->next->value <= key) {
		p->next = new Link(key, p->next);
		return;
	}
	// countinue check
	bbInsert(key, p->next);
}



void List::helpMerge(List l2) {
	if ((l2.head) == NULL)
		return;
	insert((l2.head)->value);
	l2.head = l2.head->next;
	helpMerge(l2);
}

void List::helpMakeSet() {
	for (Link* k = head, *p = head->next; p != NULL; k = k->next, p = p->next) {
		while (k->value == p->value) {
			remove(p->value);
			k = p;
			p = p->next;
		}
	}
}

List List::helpReverse(List l1)
{
	List a = l1;
	List temp;
	while (a.head != NULL)
	{
		temp.add(a.firstElement());
		a.removeFirst();
	}
	
	return temp;		
}

void List::help_oper(List::Link* l1, List::Link* l2) {
	if (l1->next == NULL)  //copy until l1 empty
		return;
	l2->next = new Link((l1->next)->value, NULL);  //copy
	help_oper(l1->next, l2->next);
}
