#include "Rational.h"
#include <math.h>
#include <cmath>


Rational:: Rational(int x, int y) {
	mone = x;
	if (!y) {
		cout << "ERROR" << endl;
		mechane = 1;
	}
	else mechane = y;
}
Rational::Rational(int x) {
	mone = x;
	mechane = 1;
	}

void Rational::setMone(int mone1) { mone = mone1; }
void Rational::setMechane(int mechane1) {
	if (mechane1)
		mechane = mechane1;
	else
		mechane = 1;
}
int Rational::getMone() const { return mone; }  
int Rational::getMechane() const { return mechane; }

void  Rational::help()
{
	if (abs(this->mone) > abs(this->mechane))// if denominator is smallest cheak if we can reduc it
	{
		if (this->mechane == 0)
		{
			this->mone = 1;//recuce 0
			return;
		}
		int m = 0;
		for (int i = abs(this->mechane); i > 0; i--)// loop all number from the smallest to 1 and chaek if the rational number can reduce withe one of them
			if (this->mone % i == 0 && this->mechane % i == 0)
			{
				m = i;
				break;
			}
		this->mone = this->mone / m;
		this->mechane = this->mechane / m;
	}
	else // numerator is smallest
	{
		if (this->mone == 0)
		{
			this->mechane = 1;
			return;
		}

		int l = 0;
		for (int i = abs(this->mone); i > 0; i--)
			if (this->mone % i == 0 && this->mechane % i == 0)
			{
				l = i;
				break;
			}
		this->mone = this->mone / l;
		this->mechane = this->mechane / l;
	}
}
void Rational::print() {
	// Function that print 
	if (!mone) {
		cout << "0" << endl;
		return;
	}
	if (mone == mechane) {
		cout << "1" << endl;
		return;
	}
	cout << mone;
	if (mechane != 1)
		cout << '/' << mechane;
}

Rational Rational::operator+(const Rational& f)const {
	Rational temp(mone * f.getMechane() + mechane * f.getMone(), mechane * f.getMechane());
	temp.help();
	return temp;
	
}
Rational Rational::operator-(const Rational& f)const {
	Rational temp(mone * f.getMechane() - mechane * f.getMone(), mechane * f.getMechane());
	temp.help();
	return temp;
}
Rational Rational:: operator/(const Rational& f)const {
	Rational temp(mone * f.getMechane(), mechane * f.getMone());
	temp.help();
	return temp;
}
Rational Rational:: operator*(const Rational& f)const {
	Rational temp(mone * f.getMone(), mechane * f.getMechane());
	temp.help();
	return temp;
}
	
bool Rational:: operator>=(Rational f) {
	return (f.getMechane() * mone >= f.getMone() * mechane);
}
bool Rational:: operator<=(Rational f) {
	return (f.getMechane() * mone <= f.getMone() * mechane);
}
bool Rational:: operator<(Rational f) {
	return (f.getMechane() * mone < f.getMone()* mechane);
}
bool Rational:: operator>(Rational f) {
	return (f.getMechane() * mone > f.getMone() * mechane);
}
bool Rational:: operator!=(Rational f) {
	return (f.getMechane() * mone != f.getMone() * mechane);
}
bool Rational:: operator==(Rational f) {
	return (f.getMechane() * mone == f.getMone() * mechane);
}

Rational Rational:: operator--(int num)
{
	Rational temp = *this;
	--* this;
	return temp;
}//post
Rational Rational::operator++(int num)
{
	Rational temp = *this;
	++* this;
	return temp;
}//post
Rational& Rational::operator++()//pre
{
	mone += mechane;
	this->help();
	return *this;
}
Rational& Rational::operator--()
{
	mone -= mechane;
	this->help();
	return *this;
}//pre