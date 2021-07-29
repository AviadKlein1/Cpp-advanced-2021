//Aviad Klein ID 315552679
//Sadna c++
//Ex.1.2
// the program get employe cards and print the employe with the lowest insertion and the employe with the high salary 

#include "worker.h"
#include <iostream>
#include<cstring>
using namespace std;
Worker one;
Worker two;
Worker w;
int main()
{
	int id;
	char name[21];
	float pay;
	int hours;
	float donate;
	
	cout << "enter details, to end enter 0:\n";
	while (true) {
		cin >> id >> name >> pay >> hours >> donate;
		if (id < 0 || pay < 0 || hours < 0 || donate < 0)
		{
			cout << "ERROR\n";
			continue;
		}
		else {


			one.setId(id);
			one.setName(name);
			one.setPay(pay);
			one.setHours(hours);
			one.setDonate(donate);
			two = one;
			break;
		}
	}

	while (true)
	{
		cin >> id;
		if (id == 0)break;//exit
		cin >> name >> pay >> hours >> donate;
		if (id < 0 || pay < 0 || hours < 0 || donate < 0)
		{
			cout << "ERROR\n";
			continue;
		}
		w.setId(id);
		w.setName(name);
		w.setPay(pay);
		w.setHours(hours);
		w.setDonate(donate);
		if (w.getDonate() <= one.getDonate() && w.getDonate()!= 0)one = w;
		if (w.salary() >= two.salary()) two = w;
	}
	cout << "minimum sum :" << one.getDonate() << " " << one.getName() << " " << one.getId() << endl;
	cout << "highest salary :" << two.salary() << " " << two.getName() << " " << two.getId() << endl;
	return 0;
}
/*
enter details, to end enter 0:
111111111  doron  35  120  6000
222222222  tal  50  55  1400
444444444  levi  45  -4  100
ERROR
333333333  naomi  30  120  800
0
minimum sum: 800 naomi 333333333
highest  salary : 5550 doron 111111111
*/