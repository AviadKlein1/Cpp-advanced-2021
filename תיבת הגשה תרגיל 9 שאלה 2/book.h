#pragma once
#include <iostream>
#include <string>
using namespace std;

class book
{
private:
	int code;
	string name;
	string author;

public:
	book() { code = 0, name = " ", author = " "; }
	friend bool operator==(book a, book b);
	friend bool operator!=(book a, book b);
	friend bool operator<=(book a, book b);
	friend bool operator>=(book a, book b);
	friend bool operator<(book a, book b);
	friend bool operator>(book a, book b);
	friend istream& operator >> (istream& in, book& a);
	friend ostream& operator << (ostream& ot, book& a);
	
};

