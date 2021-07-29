#include"Rational.h"
#include <iostream>
#include <math.h>
#include <stdlib.h> 
#include <cmath> 
using namespace std;

void Rational:: setNumerator(int x)
{
	numerator = x;
}

void Rational:: setDenominator(int y) 
{
	if (y == 0) {// if denominator is 0 set 1
		denominator = 1;
		return;
	}
	denominator = y;
}

int Rational:: getNumerator()
{
	return numerator;
}

int Rational:: getDenominator()
{
	return denominator;
}

void Rational:: print()
{
	cout << this->getNumerator() << "/" << this->getDenominator() << endl;
}

bool Rational:: equal(Rational a)// the func cheak if two rational numbers are equal
{
	if ((float (this->numerator) / float(this->denominator)) == (float(a.numerator) / float(a.denominator)))return true;
	return false;
}

Rational Rational:: add(Rational a)// sum two rational numbers
{
	Rational* temp = new Rational;
	temp->numerator = (this->numerator*a.denominator)+(a.numerator* this->denominator);
	temp->denominator = this->denominator * a.denominator;
	temp->RationalReduction();
	return *temp;
}
	
void  Rational:: RationalReduction()
{
	if (abs(this->numerator) > abs(this->denominator))// if denominator is smallest cheak if we can reduc it
	{
		if (this->denominator == 0)
		{
			this->numerator = 1;//recuce 0
			return;
		}
		int m=0;
		for (int i = abs(this->denominator); i > 0; i--)// loop all number from the smallest to 1 and chaek if the rational number can reduce withe one of them
			if (this->numerator % i == 0 && this->denominator % i == 0)
			{
				m = i;
				break;			
			}
		this->numerator = this->numerator / m;
		this->denominator = this->denominator / m;
	}
	else // numerator is smallest
	{
		if (this->numerator == 0)
		{
			this->denominator = 1;
			return;
		}

		int l=0;
		for (int i = abs(this->numerator); i > 0; i--)
			if (this->numerator % i == 0 && this->denominator % i == 0)
			{
				l = i;
				break;
			}
		this->numerator = this->numerator / l;
		this->denominator = this->denominator / l;
	}
}

