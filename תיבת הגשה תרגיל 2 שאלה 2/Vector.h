#pragma once
#include<iostream>
using namespace std;
class Vector {
private:
	int* data;
	int capacity;
	int size;
public:
	Vector();
	Vector(int size);
	Vector(const Vector& f);
	~Vector();
	int getCapacity();
	int getSize();
	void print();
	void assign(const Vector& f);
	bool isEqual(Vector& v1);
	int& at(int index);
	int strcatcat(Vector& v);
	Vector strnewcat(Vector& v);
	void clear();
	void delLast();
	void insert(int val);
};