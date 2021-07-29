#pragma once
#include<iostream>
using namespace std;
class Point {
public:
	int x;
	int y;
	void setx(int ax);
	void sety(int ay);
	int getx();
	int gety();
	float distance(Point, Point);
	friend istream& operator >> (istream& in, Point& p);
	friend ostream& operator << (ostream& os, Point& p);

};