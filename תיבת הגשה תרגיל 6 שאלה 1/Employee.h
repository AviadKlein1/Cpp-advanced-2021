#pragma once
#include <string>
#include <iostream>
using namespace std;
class Employee
{
protected:
	string name;
	int id;
	int seniority;
	float pay;
	
public:
	
	Employee();
	Employee(string , int, int);
	/*void setName(string n) { name = n; }
	void setId(int i) { id = i; }
	void setSenyority(int i) { seniority = i; }
	void setPay(float f) { pay = f; }

	string getName() { return name; }
	int getId() { return id; }
	int getSenyority() { return seniority; }
	float getPay() { return pay;}*/

	float salaryAfterBonus();
	friend istream& operator >> (istream& in, Employee& emp);
	friend ostream& operator << (ostream& ot, Employee& emp);
			
};

