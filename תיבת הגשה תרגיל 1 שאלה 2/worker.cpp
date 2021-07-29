#include "worker.h"
#include <iostream>
using namespace std;
#pragma warning(disable : 4996)
#define _CRT_SECURE_NO_WARNINGS

void Worker ::setId(int x)
{
	id = x;
}
int Worker::getId()
{
	return id;
}
void Worker::setName(char x[21])
{
	strcpy(name, x);
}
char* Worker::getName()
{
	return name;
}
void Worker::setPay(float x)
{
	pay = x;
}
float Worker::getPay()
{
	return pay;
}
void Worker::setHours(int x)
{
	hours = x;
}
int Worker::getHours()
{
	return hours;
}
void Worker::setDonate(float x)
{
	donate = x;
}
float Worker::getDonate()
{
	return donate;
}
float Worker::salary()
{
	float x = this->pay * this->hours;
	float y = this->donate;
	float sum=0;
	if ((y - 1000) > 0)
	{
		y -= 1000;
		sum = 1000 * 0.1;
		if ((y - 1000) > 0)
		{
			y -= 1000;
			sum += (1000 * 0.15);
			if ((y - 2000) > 0)
			{
				y -= 2000;
				sum += 2000 * 0.2;
				if ((y - 1000) > 0)
				{
					y -= 1000;
					sum += 1000 * 0.3;
					sum += y * 0.4;
				}
				else sum += y * 0.3;
			}
			else sum += y * 0.2;
		}
		else sum += y * 0.15;
	}
	else sum = y * 0.1;
	return x + sum;
}
