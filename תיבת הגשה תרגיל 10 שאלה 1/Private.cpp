#include "Private.h"

Private::Private(const Private& temp)
{
    this->ID = temp.ID;
    this->firstName = temp.firstName;
    this->lastName = temp.lastName;
    this->numOfOperations = temp.numOfOperations;
    this->oppRanks = temp.oppRanks;
}

bool Private::medal()
{
    if (this->numOfOperations >= 10)
    {
        int sum = 0;
        for (int i = 0; i < numOfOperations; i++)
        {
            sum += oppRanks[i];
        }
        if ((sum / numOfOperations) > 95) return true;
    }
    return false;
}

void Private::print()
{
    cout << "ID: " << ID << endl;
    cout << "first name: " << firstName << endl;
    cout << "last name: " << lastName << endl;
    cout << "num operations: " << numOfOperations << endl;
    cout << "grades: ";
    for (int i = 0; i < numOfOperations; i++)
       cout << this->oppRanks[i] << " ";
    cout << endl;
}

istream& operator>>(istream& in, Private& p)
{
    in >> p.ID  >> p.firstName >> p.lastName >> p.numOfOperations;
    if (p.numOfOperations > 0)cout << "enter " << p.numOfOperations << " grades\n";
    for (int i = 0; i < p.numOfOperations; i++)
    {
        cin >> p.oppRanks[i];
    }
    return in;
}