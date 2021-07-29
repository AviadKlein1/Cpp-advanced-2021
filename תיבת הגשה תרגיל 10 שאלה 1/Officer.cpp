#include "Officer.h"

Officer::Officer(const Officer& temp)
{
    this->ID = temp.ID;
    this->firstName = temp.firstName;
    this->lastName = temp.lastName;
    this->numOfOperations = temp.numOfOperations;
    this->sociometricScore = temp.sociometricScore;
}

bool Officer::medal()
{
   if (this->numOfOperations > 2)
        if(sociometricScore >= 92) return true;
   return false;
}

void Officer::print()
{
    cout << "ID: " << ID << endl;
    cout << "first name: " << firstName << endl;
    cout << "last name: " << lastName << endl;
    cout << "num operations: " << numOfOperations << endl;
    cout << "sociometricScore: " << sociometricScore << endl;
}

istream& operator>>(istream& in, Officer& o)
{
    in >> o.ID >> o.firstName >> o.lastName >> o.numOfOperations;
    cout << "enter number of sociometric score\n";
    in >> o.sociometricScore;
    return in;

}