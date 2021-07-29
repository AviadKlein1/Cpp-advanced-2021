#include "Circle.h"
#include "point.h"
#include <iostream>
#include <cmath>


using namespace std;

void Circle::setCenter(int x, int y)
{
		center.setX(x);
		center.setY(y);
}
void Circle::setRadius(int myRadius)
{
	radius = myRadius;
}
Point Circle::getCenter()
{
	return center;
}
int Circle::getRadius()
{
	return radius;
}
float Circle::area()
{
	return 3.14 * getRadius() * getRadius();
}
float Circle::perimeter()
{
	return 2 * 3.14 * getRadius();
}
int Circle::onInOut(Point p)//(x-a)²+(y-b)²=R²
{
	if (sqrtf(powf(p.getX() - this->getCenter().getX(), 2) + powf(p.getY() - this->getCenter().getY(), 2)) == this->getRadius())return 0;
	if (sqrtf(powf(p.getX() - this->getCenter().getX(), 2) + powf(p.getY() - this->getCenter().getY(), 2)) > this->getRadius())return 1;
	if (sqrtf(powf(p.getX() - this->getCenter().getX(), 2) + powf(p.getY() - this->getCenter().getY(), 2)) < this->getRadius())return -1;
}