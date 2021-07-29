#include"Point.h"
#include <iostream>
#pragma once
class Shape : public Point
{
public:

	int numOfPoints;
	Point* Points;
	Shape();
	Shape(int);
	Shape(const Shape& temp);
	//Shape(Shape&& temp);
	virtual ~Shape();
	friend ostream& operator<<(ostream& os, Shape& s);
	virtual void  area() const =0 ;
	virtual bool isSpecial() const = 0;
	virtual void printSpecial() const = 0;
};

