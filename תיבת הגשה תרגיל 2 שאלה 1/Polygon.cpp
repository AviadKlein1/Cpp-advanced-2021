#include "Polygon.h"
#include "Point.h"
#include <math.h>


Polygon::Polygon(int a) 
{
	cout << "in constructor\n";
	sumOfVertex = a;
	vertexes = new Point[sumOfVertex];
}

Polygon::Polygon(const Polygon& f)
{
	cout << "in copy constructor\n";
	sumOfVertex = f.sumOfVertex;
	vertexes = f.vertexes;
}

void Polygon::addPoint(Point* ver, int index)
{
	vertexes[index] = *ver;
}

int Polygon:: perimeter() 
{
	int sum = 0;
	int i = 0;
	for (i ; i < sumOfVertex-1 ; i++)
	{
		sum += (vertexes[i].distance(vertexes[i + 1]));
	}
	sum += vertexes[sumOfVertex].distance(vertexes[0]);
	return sum+1;
}

bool Polygon::equal(Polygon a)
{
	
	if (this->sumOfVertex != a.sumOfVertex)
		return false;
	for (int i = 0; i < sumOfVertex; i++)
	{
		bool flag = false;
		for (int j = 0; j < sumOfVertex; j++)
		{
			if (this->vertexes[i].getx() == a.vertexes[j].getx() && this->vertexes[i].gety() == a.vertexes[j].gety())
				flag = true;
		}
		if (!flag) return false;
	}
	return true;
}
Polygon::~Polygon() {
	cout << "in destructor\n";
	delete[] vertexes;
}
