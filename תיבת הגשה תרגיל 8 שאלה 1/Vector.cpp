#include "Vector.h"
Vector::Vector() {
	data = new float[10];
	capacity = 10;
	size = 0;
}
Vector::Vector(int size1) {
	capacity = size1;
	data = new float[capacity];
	size = 0;
}
Vector::Vector(const Vector& f) {
	capacity = f.capacity;
	size = f.size;
	data = new float[capacity];
	for (int i = 0; i < size; i++) {
		data[i] = f.data[i];
	}
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
int Vector::getSize() {
	return size;
}
bool Vector::isEmpty()
{
	return size == 0;
}
void  Vector::clear() {
	size = 0;
}
float Vector::delLast() {
	if (size == 0)
		cout << "ERROR" << endl;
	else {
		float n = data[size - 1];
		size--;
		data[size + 1] = 0;
		return n;
	}
}
void Vector::insert(float val) {
	if (size == capacity)
		cout << "ERROR" << endl;
	else {
		data[size] = val;
		size++;
	}
}

