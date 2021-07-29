#pragma once
#include <iostream>
#include<cstring>
class Worker
{
public:
	int id;
	char name[21];
	float pay;
	int hours;
	float donate;
	Worker* arr[];
	void setId(int x);
	int getId();
	void setName(char x[21]);
	char* getName();
	void setPay(float x);
	float getPay();
	void setHours(int x);
	int getHours();
	void setDonate(float x);
	float getDonate();

	float salary();

};

