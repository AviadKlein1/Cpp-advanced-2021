#include "Employee.h"
#include <string>
#include <iostream>
using namespace std;

Employee::Employee()
{
	id = 0;
	seniority = 0;
	pay = 0;
}
Employee::Employee(string name_, int id_, int seniority_)
{
	if (id_ < 0 || id_>99999999 || seniority_ < 0 )throw "ERROR";
	name = name_;
	id = id_;
	seniority = seniority_;
	
}

float Employee :: salaryAfterBonus()
{
	if (seniority <= 5) return pay + 500;
	else
	{
		int x = pay / 4;
		return pay + x;
	}

}

istream& operator>>(istream& in, Employee& emp)
{
	cout << "Enter employee details:\n";
	in >> emp.name >> emp.id >> emp.seniority;
	
	return in;
}
ostream& operator<<(ostream& ot, Employee& emp)
	{
		ot << "Employee:" <<emp.name << endl << "Employee ID:" << emp.id << endl << "Years Seniority:" << emp.seniority << endl;
		return ot;
	}
