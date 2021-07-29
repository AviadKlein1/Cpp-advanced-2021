#pragma once
#include<iostream>
using namespace std;
class date
{
private:
	int day;
	int month;
	int year;
public:

	void  setDay(int d);
	void setMonth(int m);
	void setYear(int y);

	int getDay()const;
	int getMonth()const;
	int getYear()const;

	date();
	date(int d, int m, int y);
	date(const date& d);

	date setDate(int d, int m, int y);

	date operator++(int num);
	date operator++();
	date operator+=(int day1);
	bool operator>(const date& d);
	bool operator<(const date& d);
	bool operator==(const date& d);

	void print();
};
