#include"List.h"
//-----------------class Link -------------
List::Link::Link(int val, Link* nxt) :value(val), next(nxt) {}

List::Link::Link(const Link& s) : value(s.value), next(s.next) {}


//-----------------class List -------------

List::List() : head(NULL) {}
List::List(const List& s)
{
	if (s.head == NULL)  //empty list
		head = NULL;
	else {
		head = new Link((s.head)->value, NULL);  //copy first link
		reciOperator(s.head, head);
	}
}
List List::operator=(const List& l) {
	clear();
	if (l.head == NULL) { //empty list
		head = NULL;
		return *this;
	}
	head = new Link((l.head)->value, NULL);  //copy first link
	reciOperator(l.head, head);
	return *this;
}
void List::reciOperator(List::Link* l1, List::Link* l2) {
	if (l1->next == NULL)  //copy until l1 empty
		return;
	l2->next = new Link((l1->next)->value, NULL);  //copy
	reciOperator(l1->next, l2->next);
}
List::~List()
{
	clear();
}
int List::firstElement()const
{
	if (isEmpty())
		throw "the List is empty, no first Element";
	return head->value;
}
void List::removeFirst()
{

	if (isEmpty())
		throw "the List is empty, no Elements to remove";
	Link* p = head;
	head = p->next;
	p->next = NULL;
	delete p;
}
bool List::isEmpty()const
{
	return head == NULL;
}
void List::clear()
{
	if (!isEmpty()) {
		// empty all elements from the List
		Link* next;
		for (Link* p = head; p != NULL; p = next)
		{
			// delete the element pointed to by p
			next = p->next;
			p->next = NULL;
			delete p;
		}
		// mark that the List contains no elements
		head = NULL;
	}
}
