#include "StackVector.h"
#include "Vector.h"
//template <class T>
StackVector ::StackVector(unsigned int capacity) : data(capacity)
{
	// create and initialize a Stack based on Vectors
}
//template <class T>
StackVector ::StackVector(const StackVector& s)
	: data(s.data)
{}
//template <class T>
void StackVector ::clear()
{
	// clear all elements from Stack, by setting
	// index to bottom of Stack
	data.clear();
}
//template <class T>
bool StackVector ::isEmpty()
{
	return (data.getSize() == 0);
}
//template <class T>
float StackVector ::pop()
{
	// return and remove the intopmost element in the Stack

	if (isEmpty()) throw "Stack is empty";
	return data.delLast();
}
//template <class T>
void StackVector::push(float val)
{
	// push new value onto Stack
	data.insert(val);
}
//template <class T>
float StackVector::top()
{
	// return the intopmost element in the Stack
	if (isEmpty()) throw "Stack is empty";
	return data[data.getSize() - 1];
}