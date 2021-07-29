#include "Point.h"
#include <iostream>
#include<cmath>
void Point::setx(int ax) {
	x = ax;
}
void Point::sety(int ay) {
	y = ay;
}

int Point::getx() {
	return x;
}
int Point::gety() { return y; }

float Point::distance(Point a, Point b) {

	return sqrt(pow((a.getx()-b.getx()), 2) + pow((a.gety() - b.gety()), 2));
}

istream& operator>>(istream& in, Point& p)
{
	char tav;
	in >>tav>> p.x>> tav >> p.y>> tav;
	return in;
}

ostream& operator<<(ostream& os, Point& p)
{
	os << "(" << p.x << "," << p.y << ") ";
	return os;
}

/*
How many shapes you would like to define?
3
Which shape will you choose? Circle - 1, Triangular - 3, Rectangle  4
3
Enter values of  3 points:
(0,0) (1,0) (1,1)
Which shape will you choose? Circle - 1, Triangular - 3, Rectangle  4
1
Enter radius:
4
Enter values of  1 points:
(0,0)
Which shape will you choose? Circle - 1, Triangular - 3, Rectangle  4
2
invalid input
Which shape will you choose? Circle - 1, Triangular - 3, Rectangle  4
4
Enter values of  4 points:
(0,0) (1,0) (1,1) (0,1)

points: (0,0) (1,0) (1,1)  area is: 0.5

points: (0,0) area is: 50.24
A canonical circle with a radius 4

points: (0,0) (1,0) (1,1) (0,1)  area is: 1
Square with side length 1
*/