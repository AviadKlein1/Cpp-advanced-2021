#pragma once
#include <string>
#include "Employee.h"
class PartTime :
    public Employee
{

   
public:
    int hours;
    float paymentForHour;
    PartTime() { id = 0, seniority = 0, pay = 0, hours = 0, paymentForHour = 0; };
    PartTime(int hours_, float paymentForHour_, string name_, int id_, int seniority_)
    {
        name = name_;
        id = id_;
        seniority = seniority_;
        hours = hours_;
        paymentForHour = paymentForHour_;
        pay = hours * paymentForHour;
    }
   

    friend istream& operator >> (istream& in, PartTime& emp);
    friend ostream& operator << (ostream& ot, PartTime& emp);

};