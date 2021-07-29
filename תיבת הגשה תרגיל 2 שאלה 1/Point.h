#pragma once
#include<iostream>
using namespace std;
class Point {
private:
	int x;
	int y;
public:
	void setx(int ax);
	void sety(int ay);
	int getx();
	int gety();
	int distance(Point a);
};
