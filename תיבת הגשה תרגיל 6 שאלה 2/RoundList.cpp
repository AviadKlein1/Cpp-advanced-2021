#include "RoundList.h"

RoundList::~RoundList() {
	clear();
}
RoundList::RoundList() :List() {};

void RoundList::addToEnd(int val) {
	Link* l = head;
	if (head == NULL) {
		head = new Link(val, NULL);
		head->next = head;
		return;
	}
	while (l->next != head) {
		l = l->next;
	}
	l->next = new Link(val, head);
}
int RoundList::search(int n) {
	Link* l = head;
	if (isEmpty())
		return -1;
	for (int i = 0; i < n; i++) {
		l = l->next;
	}
	return l->value;
}
void RoundList::add(int val)
{
	if (head == NULL)
	{
		head = new Link(val, NULL);
		head->next = head;
	}
	else
	{
		Link* l = head;
		while (l->next != head)//Loop to the end of the list
			l = l->next;
		head = l->next = new Link(val, head);
	}
}
void RoundList::clear()
{
	Link* next, * p;
	if (head != NULL) {
		if (head->next != NULL) {
			for (p = head->next; p != head; p = next)//loop to remove all nodes exepct the last
			{   
				next = p->next;
				p->next = NULL;
				delete p;
			}
			delete p;
			//remove the last 
			head = NULL;
		}
		else { delete head; head = NULL; }

	}
}
void RoundList::removeFirst()
{
	if (isEmpty())
		throw "the List is empty, no Elements to remove";
	Link* k = head, * p = head;
	while (k->next != head) { k = k->next; } //found last link
	if (p == k) {    //only one node at list
		p->next = NULL;
		delete p;
		head = NULL;
		return;
	}
	head = p->next;
	p->next = NULL;
	delete p;
	k->next = head;
}