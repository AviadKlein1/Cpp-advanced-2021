#pragma once
#include<iostream>
#include<cstring>
#include <string.h>


#define _CRT_SECURE_NO_DEPRECATE
#pragma warning(disable : 4996)

using namespace std;
class myString
{
private:
	char* str;
	void setString(const char* s);
public:
	myString() { str = NULL; }
	myString(char* s);
	myString(const myString& s);
	~myString();

	char* getString()const;
	bool operator>(myString& s);
	bool operator<(myString& s);
	bool operator>=(myString& s);
	bool operator<=(myString& s);
	bool operator!=(myString& s);
	bool operator=(myString& s);

	char& operator[](int index);

	myString& insert(const char* str, int index);
};
