#pragma once
#include "Stack.h"
#include "Vector.h"
//template <class T>
class StackVector : public Stack/* <T>*/
{
public:
	// constructor requires a starting size
	StackVector(unsigned int capacity);
	StackVector() {};
	StackVector(const StackVector& s);
	// Stack operations
	void clear() override;
	bool isEmpty() override;
	float pop() override;
	void push(float value) override;
	float top() override;
protected:
	// data fields
	Vector data;
};