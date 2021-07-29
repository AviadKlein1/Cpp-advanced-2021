#pragma once
#include "Private.h"
#include <iostream>
#include <string>
#include <vector>


class Commander
	: public Private
{
protected:
    bool isCombat;
public:
    Commander() : Private() { isCombat = false; };
    virtual ~Commander() {};
    Commander(const Commander& temp);
    string getFname() { return firstName; };
    string getName() { return lastName; };
    bool medal();
    bool combat() { if (isCombat) return true; return false; }
    void print();
    string soldierType() {return "Commander\n"; };
    friend istream& operator>> (istream& in, Commander& c);
    int getSoc() { throw "ERROR: this function is just for officer soldier"; };
    //friend ostream& operator<< (ostream& os, Commander& c);


};
