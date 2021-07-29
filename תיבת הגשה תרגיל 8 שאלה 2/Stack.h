#pragma once
#include <iostream>

using namespace std;
class Stack
{
public:
	virtual void clear() = 0;
	virtual bool isEmpty()const = 0;
	virtual int pop() = 0;
	virtual void push(int val) = 0;
	virtual int top() = 0;
};