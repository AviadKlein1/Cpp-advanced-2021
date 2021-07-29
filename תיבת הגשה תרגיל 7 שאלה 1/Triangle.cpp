#include "Triangle.h"
#include<cmath>

Triangle::Triangle():Shape(3)
{
}

void  Triangle::area()const
{
	float A = this->Points->distance(this->Points[0], this->Points[1]);
	float B = this->Points->distance(this->Points[1], this->Points[2]);
	float C = this->Points->distance(this->Points[2], this->Points[0]);
	//cos⁡(γ) = 〖(a〗 ^ 2 + b ^ 2 - c ^ 2) / (2∙a∙b)
	float e;
	e = (powf(A, 2) + powf(B, 2) - powf(C, 2)) / (2 * A * B);
	float ans_e = acosf(e);
	float s;
	s = (A * B * sinf(ans_e)) / 2;
	cout << s;
	return;
}

bool Triangle::isSpecial() const
{
	float A = this->Points->distance(this->Points[0], this->Points[1]);
	float B = this->Points->distance(this->Points[1], this->Points[2]);
	float C = this->Points->distance(this->Points[2], this->Points[0]);
	if (A == B == C)	return true;
	else return false;
}

void Triangle::printSpecial() const
{
	cout << "An isosceles triangle with a side length "; this->area(); cout << endl;
	return;
}


