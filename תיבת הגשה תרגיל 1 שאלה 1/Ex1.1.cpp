//Aviad Klein ID 315552679
//Sadna c++
//Ex1.1
//the program can get tow rational numbers, cheak if they equal and sum them 

#include"Rational.h"
#include <iostream>
#include <math.h>
#include <stdlib.h> 
#include <cmath> 


using namespace std;

int main()
{
	int numerator, denominator;
	char tav;
	cout << "enter two rational numbers:" << endl;
	cin >> numerator >> tav >> denominator;
	Rational r1;
	r1.setNumerator(numerator);
	r1.setDenominator(denominator);
	cin >> numerator >> tav >> denominator;
	Rational r2;
	r2.setNumerator(numerator);
	r2.setDenominator(denominator);
	
	Rational ans = r1.add(r2);
	r1.print();
	cout << "+ ";
	r2.print();
	cout << "= ";
	ans.print();
	cout << endl;
	if (r1.equal(r2))
		cout << "The two numbers are equal" << endl;
	else
	{
		cout << "The two numbers are different" << endl;
		r1.print();
		r2.print();
		cout << endl;
	}
	return 0;
}

/*
enter two rational numbers:
2/1
-2/1
2/1
+ -2/1
= 0/1

The two numbers are different
2/1
-2/1
*/