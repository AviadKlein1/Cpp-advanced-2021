#include "Shape.h"

Shape::Shape()
{
	this->numOfPoints = 0;
	this->Points = NULL;
}

Shape::Shape(int numOfPoints_)
{
	numOfPoints = numOfPoints_;
	cout << "Enter values of " << numOfPoints_ << " points:\n";
	Points = new Point[numOfPoints_];
	for (int i = 0; i < numOfPoints_; i++)
			cin >> Points[i];
	
}

Shape::Shape(const Shape& temp)
{
	this->numOfPoints = temp.numOfPoints;
	this->Points = temp.Points;
	for (int i = 0; i < numOfPoints; i++)
	{
		Points[i] = temp.Points[i];
	}
}

//Shape::Shape(Shape&& temp)
//{
//	this->numOfPoints = temp.numOfPoints;
//	this->Points = temp.Points;
//	temp = NULL;
//}

Shape::~Shape()
{
	delete[] Points;
}

ostream& operator<<(ostream& os, Shape& s)
{
	for (int i = 0; i < s.numOfPoints; i++)
	{
		os << s.Points[i];
	}
	
	// TODO: insert return statement here
	return os;
}
