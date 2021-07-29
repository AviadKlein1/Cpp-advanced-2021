#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Soldier
{
protected:
	int ID;
	string firstName;
	string lastName;
	int numOfOperations;

public:
	Soldier() { ID = 0;/* firstName = nullptr; lastName = nullptr;*/ numOfOperations = 0; }
	virtual ~Soldier() {};
	string getFname() { return firstName; };
	string getName() { return lastName; };
	Soldier(const Soldier& temp) {
		this->ID = temp.ID;
		this->firstName = temp.firstName;
		this->lastName = temp.lastName;
		this->numOfOperations = temp.numOfOperations;
	};
	int getNOO() { return numOfOperations; }
	virtual bool medal() = 0;
	virtual void print() = 0;
	virtual bool combat() { return false; };
	virtual string soldierType() = 0;
	virtual int getSoc() { return 1; };
	//friend istream& operator>> (istream& in, Soldier& s) = 0;
	//virtual friend ostream& operator<< (ostream& os, Soldier& s) = 0;
	



};

