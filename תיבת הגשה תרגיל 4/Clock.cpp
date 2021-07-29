#include "Clock.h"
#include <string.h>
using namespace std;

Clock:: Clock()
{
	hour = 00;
	minute = 00;
	second = 00;
}
Clock::Clock( int x,int y,int z)
{
	try {//exceptions
		if (x < 0) throw "Invalid time - negative number of hours.";

		if (x > 23) throw "Invalid time - more than 24 hours.";

		if (y < 0) throw "Invalid time - more than 60 seconds.";

		if (y > 59) throw "Invalid time - negative number of seconds.";

		if (z < 0) throw "Invalid time - negative number of minutes.";

		if (z > 59) throw "Invalid time - more than 60 minutes.";
	}
	catch (const char *str) 
	{
		 cout << str;
		 *this = Clock();
		 return;
	}	
	hour = x;
	minute = y;
	second = z;
}
Clock :: Clock(const Clock& temp)
{
	hour = temp.hour;
	minute = temp.minute;
	second = temp.second;
}
Clock Clock :: operator +=(int sec)
{
		if (second + sec >= 60) //çøéâåú áùðéåú
		{ 
			minute += (second + sec) / 60;
			second = (second + sec) % 60;

			if (minute >= 60) {//çøéâåú ã÷åú
				hour += minute / 60;
				minute = minute % 60;
			}

			while (hour > 23) 	hour -= 24;//çøéâåú áùòåú
		}
		else second = second + sec;

		return*this;
}
	
 


ostream& operator<<(ostream& os, Clock clock)
{	if (clock.hour < 10)
		os << "0";
	os << clock.hour << ":";

	if (clock.minute < 10)
		os << "0";
	os << clock.minute << ":";

	if (clock.second < 10)
		os << "0";
	os << clock.second;
	return os;
}

istream& operator>>(istream& is, Clock& clock)
{

	char tav;
	is >> clock.hour>> tav >> clock.minute >> tav >> clock.second;
	try
	{
		if ( (clock.hour <0 || clock.hour >23)||(clock.minute<0|| clock.minute>59)||(clock.second<0 || clock.second>59))//exceptions
			throw "Wrong time format." ;
	}
	catch (const char* str) 
	{
		cout << str;
	}

	return is;
}