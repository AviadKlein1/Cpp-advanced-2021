#include "Vector.h"
Vector::Vector() {
	data = new int[10];
	capacity = 10;
	size = 0;
}
Vector::Vector(int size1) {
	capacity = size1;
	data = new int[capacity];
	size = 0;
}

int Vector::operator[](int index) {
	if (index > size - 1)
		cout << "ERROR" << endl;
	else return data[index];
}

Vector::~Vector() {
	delete[] data;
}
int Vector::getCapacity() {
	return capacity;
}
int Vector::getSize()const {
	return size;
}
bool Vector::isEmpty()const
{
	return size == 0;
}
void  Vector::clear() {
	size = 0;
}
int Vector::delLast() {
	if (size == 0)
		cout << "ERROR" << endl;
	else {
		int n = data[size - 1];
		size--;
		data[size + 1] = 0;
		return n;
	}
}
void Vector::insert(int val) {
	if (size == capacity)
		cout << "ERROR" << endl;
	else {
		data[size] = val;
		size++;
	}
}
