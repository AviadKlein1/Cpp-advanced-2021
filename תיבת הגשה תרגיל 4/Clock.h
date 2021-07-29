#pragma once
#include <iostream>
#include <string>
using namespace std;
class Clock
{
private:
	int hour = 0;
	int minute = 0;
	int second = 0;
public:
	Clock();
	Clock(int, int, int);
	Clock(const Clock& temp);

	void set_h(int x) { hour = x; }
	void set_m(int x) { minute = x; }
	void set_s(int x) { second = x; }

	int get_h() { return hour; }
	int get_m() { return minute; }
	int get_s() { return second; }

	Clock operator +=(int);
	friend ostream& operator<<(ostream&, Clock);
	friend istream& operator>>(istream&, Clock&);
};
