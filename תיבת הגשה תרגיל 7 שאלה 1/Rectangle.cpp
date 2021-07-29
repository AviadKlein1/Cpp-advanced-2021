#include "Rectangle.h"

Rectangle::Rectangle():Shape(4)
{
}

void  Rectangle::area() const
{
	float A = this->Points->distance(this->Points[0], this->Points[1]);
	float B = this->Points->distance(this->Points[1], this->Points[2]);
	float C = this->Points->distance(this->Points[2], this->Points[3]);
	float D = this->Points->distance(this->Points[3], this->Points[0]);

	cout << (A*B);
	return;
}

bool Rectangle::isSpecial() const
{
	float A = this->Points->distance(this->Points[0], this->Points[1]);
	float B = this->Points->distance(this->Points[1], this->Points[2]);
	float C = this->Points->distance(this->Points[2], this->Points[3]);
	float D = this->Points->distance(this->Points[3], this->Points[0]);

	if (A == B) return true;
	else return false;
}

void Rectangle::printSpecial() const
{
	float A = this->Points->distance(this->Points[0], this->Points[1]);
	cout << "Square with side length " << A << endl;
	return;
}

