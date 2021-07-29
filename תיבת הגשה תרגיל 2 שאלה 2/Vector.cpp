#include "Vector.h"
#include <iostream>
using namespace std;

Vector::Vector() {
	data = new int[2];
	capacity = 2;
	size = 0;
}
Vector::Vector(int size1) {
	capacity = size1;
	data = new int[capacity];
	size = 0;
}
Vector::Vector(const Vector& f) {
	capacity = f.capacity;	
	size = f.size;
	data = new int[capacity];
	for (int i = 0; i < size; i++) {
		data[i] = f.data[i];
	}
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
void Vector::print() {
	cout << "capacity: " << capacity << " size: " << size;
	cout << " values: ";
	for (int i = 0; i < size; i++) {
		cout << data[i] << " ";
	}
	cout << endl;
}
void Vector::assign(const Vector& f) {
	capacity = f.capacity;
	size = f.size;
	data = new int[capacity];
	for (int i = 0; i < size; i++) {
		data[i] = f.data[i];
	}
}
bool  Vector::isEqual(Vector& v) {
	if (size != v.getSize())
		return false;
	for (int i = 0; i < size; i++) {
		if (v.data[i] != data[i])
			return false;
	}
	return true;
}
int& Vector::at(int index) {
	if (index > size - 1 || index<=0)
	{
		cout << "ERROR" << endl;
		return data[0];
	}
	else return data[index];

}
int Vector::strcatcat(Vector& v) {
	int sum = 0;
	if (size != v.getSize())
	{
		cout << "ERROR" << endl;
		return -1;
	}
	else {
		for (int i = 0; i < size; i++)
		{
			sum += data[i] * v.data[i];
		}
		return sum;
	}

}
Vector Vector::strnewcat(Vector& v) {
	Vector vec(capacity + v.getCapacity());
	vec.capacity = capacity + v.getCapacity();
	vec.size = size + v.getSize();
	int j = 0;
	for (int i = 0; i < size; i++, j++) {
		vec.data[j] = data[i];
	}
	for (int i = 0; i < v.getSize(); i++, j++)
		vec.data[j] = v.data[i];
	return vec;
}
void  Vector::clear() {
	size = 0;
}
void Vector::delLast() {
	if (size == 0)
		cout << "ERROR" << endl;
	else {
		data[size - 1] = 0;
		size--;
	}
}
void Vector::insert(int val) {
	if (size == capacity)
	{
		Vector* vec = new Vector(capacity * 2);
		vec->capacity = this->capacity * 2;
		vec->size = this->size;
		
		int i = 0;
		for (i ; i < size; i++)
			vec->data[i] = this->data[i];
		assign(*vec);
		this->size++;
		this -> data[i] = val;
				
		
	}
	else {
		data[size] = val;
		size++;
	}
}
