#pragma once
#include "Vector.h"
#include<iostream>
using namespace std;

class StackVector : public Stack
{
public:
	StackVector(unsigned int capacity);
	StackVector() {};
	StackVector(const StackVector& s);
	void clear()override;
	bool isEmpty()const override;
	int pop() override;
	void push(int value) override;
	int top() override;
protected:
	Vector data;
};



StackVector::StackVector(unsigned int capacity) : data(capacity) {}

StackVector::StackVector(const StackVector& s)
	: data(s.data)
{}

void StackVector::clear()
{
	data.clear();
}

bool StackVector::isEmpty()const
{
	return (data.getSize() == 0);
}

int StackVector::pop()
{
	if (isEmpty()) throw "Stack is empty";
	return data.delLast();
}

void StackVector::push(int val)
{
	data.insert(val);
}

int StackVector::top()
{
	if (isEmpty()) throw "Stack is empty";
	return data[data.getSize() - 1];
}