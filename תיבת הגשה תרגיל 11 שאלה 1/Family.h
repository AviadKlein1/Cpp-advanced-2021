#pragma once
#include<iostream>
using namespace std;

class Family
{
public:
	int key;
	char familyName[20];
	int familyMembers;
	int phone;
	bool classes[6];
	Family();
	int getKey() { return key; }
	friend istream& operator >> (istream& in, Family& fm);
	bool* getClasses() { return classes; }
	void setClasses(bool* classes_);
		
};

