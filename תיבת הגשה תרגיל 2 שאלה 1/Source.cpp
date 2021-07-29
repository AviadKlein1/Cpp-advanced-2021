//Aviad Klein ID 315552679
//Sadna c++
//Ex 2.1
//The program gets two polygons and calculet ther perimeter and check if they are equal
#include "Point.h"
#include "Polygon.h"


int main() {
	int size, x, y;
	char tav;
	do
	{
	cout << "enter number of sides:" << endl;
	cin >> size;
	if(size<3) cout << "ERROR\n";
	} while (size < 3);
	
	
	Polygon p1(size);
	cout << "enter the point values:\n";
	for (int i = 0; i < size; i++)
	{
		cin >> tav >> x >> tav >> y >> tav;
		if (x < 0 || y < 0) cout << "ERROR\n";
		Point* temp = new Point;
		temp->setx(x);
		temp->sety(y);
		p1.addPoint(temp, i);
		delete temp;		
	}

	do
	{
		cout << "enter number of sides:" << endl;
		cin >> size;
		if (size < 3) cout << "ERROR\n";
	} while (size < 3);

	Polygon p2(size);
	cout << "enter the point values:\n";
	for (int i = 0; i < size; i++)
	{
		cin >> tav >> x >> tav >> y >> tav;
		if (x < 0 || y < 0)cout << "ERROR\n";
		Point* temp = new Point;
		temp->setx(x);
		temp->sety(y);
		p2.addPoint(temp, i);
		delete temp;
	}
	if (p1.equal(p2)==1)
	{
		cout << "equal. perimeter:" << p1.perimeter() << endl;
	}
	else
	{
		cout << "perimeter:" << p1.perimeter() << endl;
		cout << "perimeter:" << p2.perimeter() << endl;
	}
	return 0;
}