#pragma once
#include <iostream>
#include "Soldier.h"
#include <string>
#include <vector>


class Private :
    public Soldier
{
protected:
    int* oppRanks;
public:
    Private() : Soldier() {
        oppRanks = new int[numOfOperations];
    };
    virtual ~Private() { if (oppRanks) delete[]oppRanks;};
    Private(const Private& temp);
    string getFname() { return firstName; };
    string getName() { return lastName; };
    virtual bool medal();
    virtual void print();
    virtual string soldierType() {return "Private\n"; };
    friend istream& operator>> (istream& in, Private& p);
    virtual int getSoc() { throw "ERROR: this function is just for officer soldier"; };
    //virtual friend ostream& operator<< (ostream& os, Private& p);

};

