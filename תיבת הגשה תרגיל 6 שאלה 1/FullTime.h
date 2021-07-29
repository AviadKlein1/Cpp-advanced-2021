#pragma once
#include <string>
#include "Employee.h"
class FullTime :
    public Employee
{
protected:
    float yearPaynment;
public:

    FullTime()  { id =0, seniority=0, pay =0, yearPaynment = 0; };
    FullTime(string name_, int id_, int seniority_, float yP)  { name = name_, id = id_, seniority = seniority_, pay = 0, yearPaynment = yP; if (yearPaynment < 0 )throw "ERROR"; };
    float salary() {
        return(yearPaynment / 12);
    }

    friend istream& operator >> (istream& in, FullTime& emp);
    friend ostream& operator << (ostream& ot, FullTime& emp);

};

