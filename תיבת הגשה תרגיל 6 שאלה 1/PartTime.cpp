#include "PartTime.h"

istream& operator>>(istream& in, PartTime& emp)
{
	in >> (Employee&)emp;
	in >> emp.hours >> emp.paymentForHour;
	if (emp.id < 0 || emp.seniority < 0 || emp.hours < 0|| emp.paymentForHour<0)throw "ERROR";
	emp.pay = emp.hours * emp.paymentForHour;
	return in;
}

ostream& operator<<(ostream& ot, PartTime& emp)
{
	ot <<(Employee&)emp;
	ot << "Hours:" << emp.hours << endl;
	ot << "Salary per Month:" << emp.pay << endl;
	return ot;
}