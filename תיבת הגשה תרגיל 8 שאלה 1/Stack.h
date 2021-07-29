#include <iostream>

using namespace std;

//template <class T>
class Stack
{
public:
	virtual void clear() = 0;
	virtual bool isEmpty() = 0;
	virtual float pop() = 0;
	virtual void push(float val) = 0;
	virtual float top() = 0;
};
