//Aviad klein ID 315552679
//Sadna in c++
//Exercise 6.1
//Progrem for employes at university

#include "FullTime.h"
#include "Employee.h"
#include "PartTime.h"
#include <iostream>
#include <string>


using namespace std;
int main()
{
	FullTime arrF[3];
	for (int i = 0; i < 3; i++)
	{
		try
		{
			cin >> arrF[i];
		}
		catch (const char* str)
		{
			cout << str << endl;
			i--;
		}
	}


	PartTime arrP[3];
	for (int i = 0; i < 3; i++)
	{
		try
		{
			cin >> arrP[i];
		}
		catch (const char* str)
		{
			cout << str << endl;
			i--;
		}
	}


	for (int i = 0; i < 3; i++)
	{
		cout << arrF[i];
		cout << "After Bonus: " << arrF[i].salaryAfterBonus() << endl;
	}


	for (int i = 0; i < 3; i++)
	{
		cout << arrP[i];
		cout << "After Bonus: " << arrP[i].salaryAfterBonus() << endl;
	}
	return 0;
}

/*

Enter employee details:
aaaa
1111
3
555555
Enter employee details:
bbbb
2222
5
777777
Enter employee details:
cccc
3333
6
888888
Enter employee details:
yyy
3
123
23
4
Enter employee details:
ggg
3333
3
45
56
Enter employee details:
rrrr
2345
44
32
12
Employee:aaaa
Employee ID:1111
Years Seniority:3
Salary per Month:46296.3
After Bonus: 46796.3
Employee:bbbb
Employee ID:2222
Years Seniority:5
Salary per Month:64814.8
After Bonus: 65314.8
Employee:cccc
Employee ID:3333
Years Seniority:6
Salary per Month:74074
After Bonus: 92592
Employee:yyy
Employee ID:3
Years Seniority:123
Hours:23
Salary per Month:92
After Bonus: 115
Employee:ggg
Employee ID:3333
Years Seniority:3
Hours:45
Salary per Month:2520
After Bonus: 3020
Employee:rrrr
Employee ID:2345
Years Seniority:44
Hours:32
Salary per Month:384
After Bonus: 480
*/