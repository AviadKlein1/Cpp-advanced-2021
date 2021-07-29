#pragma once
#include<iostream>
using namespace std;
class Vector
{
private:
	float* data;
	int capacity;
	int size;
public:
	Vector();
	Vector(int size);  
	Vector(const Vector& f);
	~Vector();
	int getCapacity();
	int getSize();
	bool isEmpty();
	void clear();
	float delLast();
	void insert(float val);
	int operator[](int index);

};
