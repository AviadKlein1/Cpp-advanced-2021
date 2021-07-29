#include "myString.h"
#include <string.h>
#include<cstring>
#include <cstdlib>


#define _CRT_SECURE_NO_DEPRECATE
#pragma warning(disable : 4996)

myString::myString(char* s) { 
	setString(s);
}
myString::myString(const myString& s) {// áðàé äòú÷ä 
	setString(s.getString());
}
myString::~myString() {
	if (str)
		delete[]str;
	str = NULL;
}

void myString::setString(const char* s) {   //äùîä 
	if (s) {
		str = new char[strlen(s) + 1];
		/*strcpy_s(str, strlen(s) + 1, s);*/
		strcpy(str, s);
	}
	else str = NULL;
}
char* myString::getString()const {
	return str;
}


bool myString:: operator>(myString& s) {
	if (strcmp(str, s.getString()) > 0)
		return true;
	return false;
}
bool  myString::operator<(myString& s) {
	if (strcmp(str, s.getString()) < 0)
		return true;
	return false;
}
bool  myString::operator>=(myString& s) {
	if (strcmp(str, s.getString()) >= 0)
		return true;
	return false;
}
bool  myString:: operator<=(myString& s) {
	if (strcmp(str, s.getString()) <= 0)
		return true;
	return false;
}
bool  myString::operator!=(myString& s) {
	if (strcmp(str, s.getString()) != 0)
		return true;
	return false;
}
bool  myString::operator=(myString& s) {
	if (strcmp(str, s.getString()) == 0)
		return true;
	return false;
}

char& myString::operator[](int index) {
	if (index < 0 || index > strlen(this->getString())-1)
	{
		cout << "ERROR";
		exit(-1);
	}
	else
		return str[index];
}

myString& myString::insert(const char* a, int n) {

	if (n < 0 || n > strlen(a))
	{
		cout << "ERROR" << endl;
		myString* newStr = new myString();
		return *newStr;
	}
	
		int num = strlen(this->getString())+ strlen(a);
		char* tmp = new char[num];

		strncpy(tmp, this->str, n);
		tmp[n] = '\0';

		strcat(tmp, a);
		strcat(tmp, this->str + n);
		myString* newstr = new myString(tmp);
	
		return *newstr;
}
