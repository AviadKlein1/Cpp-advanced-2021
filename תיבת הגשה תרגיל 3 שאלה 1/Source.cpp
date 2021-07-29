//Aviad Klein ID 315552679
//Sadna c++
//Ex 3.1
//the program defined all operators for rational number

#include <iostream>
#include "Rational.h"
#include <math.h>
#include <cmath>



using namespace std;
//äâãøä æå òáåø ÷øéàåú äúëðéú áìáã
enum { add, sub, mult, divi, addPre, addPost, subPre, subPost, big, small, bigEq, smallEq, eequal, notEqual };
int main()
{
	int numerator, denominator;
	char tav;
	int op = 1;
	while (op != 0)
	{
		cout << "enter two rational numbers:" << endl;
		cin >> numerator >> tav >> denominator;
		Rational r1(numerator, denominator) ;
		r1.help();
		cin >> numerator >> tav >> denominator;
		Rational r2(numerator, denominator);
		r2.help();
		switch (0)
		{
		case add:r1.print(); cout << " + "; r2.print(); cout << " = "; (r1 + r2).print(); cout << endl;

		case sub:r1.print(); cout << " - "; r2.print(); cout << " = "; (r1 - r2).print(); cout << endl;

		case mult:r1.print(); cout << " * "; r2.print(); cout << " = "; (r1 * r2).print(); cout << endl;

		case divi:r1.print(); cout << " / "; r2.print(); cout << " = "; (r1 / r2).print(); cout << endl;

		case addPre:cout << "++"; cout << "("; r1.print();  cout << ") = "; (++r1).print(); cout << endl;

		case addPost: cout << "("; r1.print(); cout << ")++"; cout << " = "; (r1++).print(); cout << endl;

		case subPre:cout << "--"; cout << "("; r1.print();  cout << ") = "; (--r1).print(); cout << endl;

		case subPost:cout << "("; r1.print(); cout << ")--"; cout << " = "; (r1--).print(); cout << endl;

		case big:r1.print(); cout << " > "; r2.print(); cout << " ? ";  (r1 > r2) ? cout << "yes" : cout << "no"; cout << endl;

		case small:r1.print(); cout << " < "; r2.print(); cout << " ? ";  (r1 < r2) ? cout << "yes" : cout << "no"; cout << endl;

		case bigEq:r1.print(); cout << " >= "; r2.print(); cout << " ? ";  (r1 >= r2) ? cout << "yes" : cout << "no"; cout << endl;

		case smallEq:r1.print(); cout << " <= "; r2.print(); cout << " ? ";  (r1 <= r2) ? cout << "yes" : cout << "no"; cout << endl;

		case eequal:r1.print(); cout << " == "; r2.print(); cout << " ? ";  (r1 == r2) ? cout << "yes" : cout << "no"; cout << endl;

		case notEqual:r1.print(); cout << " != "; r2.print(); cout << " ? ";  (r1 != r2) ? cout << "yes" : cout << "no"; cout << endl;

		}
		cout << "enter 1 to cont. 0 to exit." << endl;
		cin >> op;
	}

	return 0;
}
/*
enter two rational numbers:
1/2 3/4
1/2 + 3/4 = 5/4
1/2 - 3/4 = -1/4
1/2 * 3/4 = 3/8
1/2 / 3/4 = 2/3
++(1/2) = 3/2
(3/2)++ = 3/2
--(5/2) = 3/2
(3/2)-- = 3/2
1/2 > 3/4 ? no
1/2 < 3/4 ? yes
1/2 >= 3/4 ? no
1/2 <= 3/4 ? yes
1/2 == 3/4 ? no
1/2 != 3/4 ? yes
enter 1 to cont. 0 to exit.
0

*/
