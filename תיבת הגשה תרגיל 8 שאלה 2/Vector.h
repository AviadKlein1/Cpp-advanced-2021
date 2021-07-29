#pragma once
#include<iostream>
using namespace std;
class Vector
{
protected:
	int* data;
	int capacity;
	int size;
public:
	Vector();
	Vector(int size);
	~Vector();
	int getCapacity();
	int getSize()const;
	bool isEmpty()const;
	void clear();
	int delLast();
	void insert(int val);
	int operator[](int index);

};