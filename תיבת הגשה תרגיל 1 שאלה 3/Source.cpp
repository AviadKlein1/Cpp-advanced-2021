#include "Circle.h"
#include "point.h"
#include <iostream>

using namespace std;
Circle A;
Circle B;
Circle C;

int main()
{
	int x, y, radius;
	char tav;
	cout << "enter the center point and radius of 3 circles:\n";
	cin >> tav >> x >> tav>> y>> tav >> radius;
	A.setCenter(x, y);
	A.setRadius(radius);
	cin >> tav >> x >> tav >> y >> tav >> radius;
	B.setCenter(x, y);
	B.setRadius(radius);
	cin >> tav >> x >> tav >> y >> tav >> radius;
	C.setCenter(x, y);
	C.setRadius(radius);

	cout << "perimeter: A: " << A.perimeter() << " B: " << B.perimeter() << " C: " << C.perimeter() << endl;
	cout << "area: A: " << A.area() << " B: " << B.area() << " C: " << C.area() << endl;
	cout << "enter points until (0,0):\n";
	Point* pointsArr =  new Point[20];
	int i = 0;
	int a=45, b=6;
	while (!(a==0 && b==0))
	{
		cin >> tav >> a >> tav >> b >> tav;
		pointsArr[i].setX(a);
		pointsArr[i].setY(b);
		i++;
	}

	int Asum = 0, Bsum = 0, Csum = 0;
	for (int j = 0; j < i-1; j++)
		if (A.onInOut(pointsArr[j]) <= 0)Asum += 1;
	for (int j = 0; j < i-1; j++)
		if (B.onInOut(pointsArr[j]) <= 0)Bsum += 1;
	for (int j = 0; j < i-1; j++)
		if (C.onInOut(pointsArr[j]) <= 0)Csum += 1;
	
	cout << "num of points in circle: A:" << Asum << " B:" << Bsum << " C:"<<Csum << endl;
	delete []pointsArr;
	return 0;
}