//Aviad klein ID 315552679
//Sadna c++
//Exsercise 7.1
//Polimorfise Program that take care on 3 kind of shapes
 
#include "Point.h"
#include <iostream>
#include<cmath>
#include "Rectangle.h"
#include "Triangle.h"
//#include "Shape.h"
#include "Circle.h"

using namespace std;
enum Options
{
	circle = 1, triangle = 3, rectangle
};


int main()
{
	int n; int opt;
	cout << "How many shapes you would like to define?\n";
	cin >> n;
	Shape** s = new Shape*[n];

	for (int i = 0; i < n; i++)
	{
		cout << "Which shape will you choose? Circle - 1, Triangular - 3, Rectangle - 4\n";
		cin >> opt;
		switch (opt)
		{
		case 1:
			float r;
			cout << "Enter radius:\n";
			cin >> r;
			s[i] = new Circle(r);
			break;
		case 3:
			s[i] = new Triangle;
			break;
		case 4:
			s[i] = new Rectangle;
			break;
		default:
			cout << "invalid input\n";
			i--;
			break;
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << "points: ";
		cout << *s[i];
		/*if (s[i]->numOfPoints == 1) cout << s[i]->Points[0];
		if (s[i]->numOfPoints == 3)cout << s[i]->Points[0] << s[i]->Points[1] << s[i]->Points[2];
		if (s[i]->numOfPoints == 4)cout << s[i]->Points[0] << s[i]->Points[1] << s[i]->Points[2] << s[i]->Points[3];*/


		cout << "  area is: "; s[i]->area(); cout << endl;
		if (s[i]->isSpecial()) s[i]->printSpecial();
	}


	return 0;
}
