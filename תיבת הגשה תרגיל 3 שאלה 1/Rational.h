#pragma once
#include<iostream>
using namespace std;
class Rational {
private:
	int mone;
	int mechane;
public:
	Rational(int x, int y);
	Rational(int x);
	void setMone(int mone);
	int getMone() const;
	void setMechane(int mechane);
	int getMechane() const;
	void print();
	void help();

	Rational operator-(const Rational& f)const;
	Rational operator/(const Rational& f)const;
	Rational operator+(const Rational& f)const;
	Rational operator*(const Rational& f)const;
	
	Rational& operator++();       // Prefix increment operator.
	Rational operator++(int num);     // Postfix increment operator.

	Rational& operator--();       // Prefix increment operator.
	Rational operator--(int num);     // Postfix increment operator.


	bool operator>=(Rational f);
	bool operator<=(Rational f);

	bool operator>(Rational f);
	bool operator<(Rational f);

	bool operator!=(Rational f);
	bool operator==(Rational f);

	
};