#include "Point.h"
#include<math.h>
void Point::setx(int ax) {
	x = ax;
}
void Point::sety(int ay) {
	y = ay;
}

int Point::getx() {
	return x;
}
int Point::gety()
{ return y; }

int Point::distance(Point a)
{
	int temp = pow(a.getx() - this->getx(), 2) + pow(a.getx() - this->getx(), 2);
	return sqrt(temp);
}

