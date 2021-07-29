#pragma once
#include "Queue.h"
#include "StackVector.h"
#include<iostream>
using namespace std;
class QueueStack : public Queue
{
protected:
	Stack* data;
public:
	QueueStack();
	void clear()override;
	int dequeue()override;
	void enqueue(int value)override;
	int front()override;
	bool isEmpty() const override;
};

QueueStack::QueueStack() { data = new StackVector(10); }

void QueueStack::clear() {
	data->clear();
}

int QueueStack::dequeue() { //with two stacks
	Stack* p = new StackVector;
	while (!data->isEmpty()) {  
		p->push(data->pop());
	}
	int myNum = p->pop();  
	while (!p->isEmpty()) {  
		data->push(p->pop());
	}
	delete p;
	return myNum;
}
void QueueStack::enqueue(int value) {
	data->push(value);   
}

int QueueStack::front() {
	Stack* p = new StackVector();
	while (!data->isEmpty()) {  
		p->push(data->pop());
	}
	int first = p->top(); 
	while (!p->isEmpty()) {  
		data->push(p->pop());
	}
	delete p;
	return first;
}

bool QueueStack::isEmpty()const {

	return data->isEmpty();
}