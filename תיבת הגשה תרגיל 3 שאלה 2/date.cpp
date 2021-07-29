#include"date.h"
void date::setDay(int d) { day = d; }
void date::setMonth(int m) { month = m; }
void date::setYear(int y) { year = y; }

int date::getDay()const { return day; }
int date::getMonth()const { return month; }
int date::getYear()const { return year; }

date::date() {
	day = 1;
	month = 1;
	year = 1920;
}
date::date(int d, int m, int y) {
	if (d < 1 || d>30) {
		cout << "Error day" << endl;
		d = 1;
	}
	day = d;
	if (m < 1 || m>12) {
		cout << "Error month" << endl;
		m = 1;
	}
	month = m;
	if (y < 1920 || y>2099) {
		cout << "Error year" << endl;
		y = 1920;
	}
	year = y;
}

date::date(const date& d) {
	day = d.getDay();
	month = d.getMonth();
	year = d.getYear();
}
date date::setDate(int d, int m, int y) {
	if (d > 0 && d < 31 && m > 0 && m < 13 && y > 1969 && y < 2100) {
		day = d; month = m; year = y;
	}
	return*this;
}
date date::operator ++() {
	if (day == 30 && month == 12 && year == 2099) {
		day = 1; month = 1; year = 1920;
	}
	else if (day == 30 && month == 12) {
		day = 1; month = 1; year++;
	}
	else if (day == 30) {
		day = 1; month++;
	}
	else day++;
	return *this;
}
date date:: operator++(int num) {
	date p = *this;
	if (day == 30 && month == 12 && year == 2099) {
		day = 1; month = 1; year = 1920;
	}
	else if (day == 30 && month == 12) {
		day = 1; month = 1; year++;
	}
	else if (day == 30) {
		day = 1; month++;
	}
	else day++;
	return p;
}
date date:: operator+=(int day1) {
	if (day1 + day > 30 && year < 2099 && month == 12) {
		day = day1 + day - 30; month = 1; year++;
	}
	else if (day1 + day > 30 && year == 2099 && year == 12) {
		day = 1; month = 1; year = 1920;
	}
	else if (day1 + day > 30 && year < 2099 && month < 12) {
		day = day1 + day - 30; month++;
	}
	else if (day1 + day < 30)
		day = day1 + day;
	return *this;
}
bool date:: operator>(const date& d) {
	if (year > d.getYear())
		return true;
	else if (year == d.getYear() && month > d.getMonth())
		return true;
	else if (year == d.getYear() && month == d.getMonth() && day > d.getDay())
		return true;
	return false;
}
bool date::operator<(const date& d) {
	if (year < d.getYear())
		return true;
	else if (year == d.getYear() && month < d.getMonth())
		return true;
	else if (year == d.getYear() && month == d.getMonth() && day < d.getDay())
		return true;
	return false;
}
bool date::operator==(const date& d) {
	if (year == d.getYear() && month == d.getMonth() && day == d.getDay())
		return true;
	return false;
}
void date::print() {
	cout << day << "/" << month << "/" << year << endl;
}
