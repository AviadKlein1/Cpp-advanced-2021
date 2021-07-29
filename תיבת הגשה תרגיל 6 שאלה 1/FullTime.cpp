#include "FullTime.h"

istream& operator>>(istream& in, FullTime& emp)
{
	in >> (Employee&)emp;
	in >> emp.yearPaynment;
	if (emp.id < 0 || emp.seniority < 0|| emp.yearPaynment<0)throw "ERROR";
	emp.pay = emp.salary();
	return in;
}
ostream& operator <<(ostream& ot, FullTime& emp)
{
	ot <<(Employee&)emp;
	ot << "Salary per Month:" << emp.pay << endl;
	return ot;
}