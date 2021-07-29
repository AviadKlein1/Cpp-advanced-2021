#pragma once
#include "Soldier.h"
#include <iostream>
#include <string>
#include <vector>


class Officer
	: public Soldier
{
protected:
	int sociometricScore;
public:
	Officer() : Soldier() { sociometricScore=0; };
	virtual ~Officer() {};
	Officer(const Officer& temp);
	bool medal();
	void print();
	string getFname() { return firstName; };
	string getName() { return lastName; };
	int getSoc() { return sociometricScore; };
	string soldierType() { return "Officer\n"; };
	friend istream& operator>> (istream& in, Officer& o);
	//friend ostream& operator<< (ostream& os, Officer& o);


};

