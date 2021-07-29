#pragma once
#include "Point.h"
#include<iostream>
using namespace std;

class Polygon {
private:
	Point* vertexes;
	int sumOfVertex;
public:
	Polygon(int a);
	Polygon(const Polygon& f);
	~Polygon();
	void addPoint(Point* pointH, int side);
	int perimeter();
	bool equal(Polygon a);

};
