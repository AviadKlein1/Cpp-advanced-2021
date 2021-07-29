#include "Commander.h"


Commander::Commander(const Commander& temp)
{
    this->ID = temp.ID;
    this->firstName = temp.firstName;
    this->lastName = temp.lastName;
    this->numOfOperations = temp.numOfOperations;
    this->oppRanks = temp.oppRanks;
    this->isCombat = temp.isCombat;
}

bool Commander::medal()
{
    if (this->numOfOperations >= 7)
    {
        int sum = 0;
        for (int i = 0; i < numOfOperations; i++)
        {
         sum += oppRanks[i];
        }
        if (((sum / numOfOperations) > 90) && isCombat) return true;
    }
    return false;
}

void Commander::print()
{
    cout << "ID: " << ID << endl;
    cout << "first name: " << firstName << endl;
    cout << "last name: " << lastName << endl;
    cout << "num operations: " << numOfOperations << endl;
    cout << "grades: ";
    for (int i = 0; i < numOfOperations; i++)
    {
        cout << oppRanks[i] << " ";
    }
    cout << endl;
    cout << "combat: ";
    if (isCombat)cout << "yes";
    else cout << "no";
    cout << endl;
}

istream& operator>>(istream& in, Commander& c)
{
    in >> c.ID >> c.firstName >> c.lastName >> c.numOfOperations;
   
    if (c.numOfOperations > 0)cout << "enter " << c.numOfOperations << " grades\n";
    for (int i = 0; i < c.numOfOperations; i++)
        cin >> c.oppRanks[i];
    
    cout << "enter 1 if the soldier is combat and 0 if not\n";
    int x = 0;
    cin >> x;
    if (x == 0)c.isCombat = false;
    else c.isCombat = true;
    return in;
}