//Aviad klein ID 315552679
//Exs 10
// Sadna c++
//Program for medals at militry operation

#include <iostream>
#include "Soldier.h"
#include "Private.h"
#include "Commander.h"
#include "Officer.h"
#include <vector>
#include <algorithm>
#include <string>
using namespace std;



enum option {
	stop,	//	ñéåí äúåëðéú
	addNewSoldier,	//	äåñôú çééì çãù
	medalList,	//	äãôñú ôøèé ëì äçééìéí äæëàéí ìöì"ù
	mostSociometric,	//	äãôñú ùí (îùôçä åôøèé) ùì  äçééì áòì öéåï ñåöéåîèøé î÷ñéîìé 
	countMedalPrivate,	//	äãôñú îñôø äçééìéí äèéøåðééí äæëàéí ìöì"ù
	noCombatCommander,	//	äãôñú ùîåú (îùôçä åôøèé) ùì äîô÷ãéí ùàéðí á÷øáé
	overSoldier,	//	äãôñú äåãòä îúàéîä, äàí ÷ééí çééì ùäùúúó áéåúø î- 15  îáöòéí öáàééí
	removeOfficer,	//	îçé÷ú ëì äçééìéí ä÷öéðéí ùìà äùúúôå ëìì áîáöò öáàé
};

void add(vector<Soldier*>& vec)
{
	int x = 0;
	cout << "enter 1 to add a private soldier\n";
	cout << "enter 2 to add a commander soldier\n";
	cout << "enter 3 to add a officer soldier\n";
	cin >> x;
	if (x == 1) { 
		Private* p = new Private;
		cout << "enter id, first name, last name and number Of operations\n";
		cin >> *p;
		vec.push_back(p);
	}
	if (x == 2) {
		Commander* c = new Commander;
		cout << "enter id, first name, last name and number Of operations\n";
		cin >> *c;
		vec.push_back(c);
	}
	if (x == 3) {
		Officer* o = new Officer;
		cout << "enter id, first name, last name and number Of operations\n";
		cin >> *o;
		vec.push_back(o);
	}
}  
void medal(vector<Soldier*> vec)
{
	vector<Soldier*> ::iterator it;
	it = vec.begin();
	for (it = vec.begin(); it != vec.end(); it++)
		if ((*it)->medal())(*it)->print();
	return;
}
Soldier* mostSociometricScore(vector<Soldier*> vec)
{
	int high = 0;
	Soldier* temp = nullptr;
	vector<Soldier*> ::iterator it;
	for (it = vec.begin(); it != vec.end(); it++) 
	{
		if ((*it)->soldierType() == "Officer\n")
			if (high < (*it)->getSoc())
			{
				temp = (*it);
				high = (*it)->getSoc();
			}
	}
		if (high == 0) { cout << "NULL\n"; return nullptr; };
	 return temp;
}  
void noCombat(vector<Soldier*> vec)
{
	vector<Soldier*> ::iterator it;
	for (it = vec.begin(); it != vec.end(); it++)
	{
		if ((*it)->soldierType() == "Commander\n")
			if (!(*it)->combat()) (*it)->print();		
	}
}
int countMedal(vector<Soldier*> vec)
{
	int sum = 0;
	vector<Soldier*> ::iterator it;
	it = vec.begin();
	for (it = vec.begin(); it != vec.end(); it++)
		if ((*it)->medal()&& (*it)->soldierType() == "Private\n")sum += 1;
	return sum;
}
bool moreThan15(vector<Soldier*> vec)
{
	vector<Soldier*> ::iterator it;
	for (it = vec.begin(); it != vec.end(); it++)
	{
		if ((*it)->getNOO() > 15) return true;
	}
	return false;
}
bool removeOff(Soldier* sol)
{
	if ((sol)->getNOO() == 0 && (sol)->soldierType() == "Officer\n")return true;
	else return false;
}
void removeNoOper(vector<Soldier*>& vec)
{
	vector<Soldier*> ::iterator vbegin = vec.begin();
	vector<Soldier*> ::iterator vend = vec.end();
	vector<Soldier*> ::iterator it = vbegin;
	
	for (int i=0; i< vec.size();i++)
	{
		if (vec.empty())return;
		if (removeOff(*it)) {
			vec.erase(it);
		}
		else it++;
	}	
	for (it = vec.begin(); it != vec.end(); it++)
		(*it)->print();
}

int main()
{
	vector <Soldier*> vec;   // äöäøä òì åå÷èåø àå øùéîä ùì çééìéí
	int op;
	cout << "enter 0-7\n";
	cin >> op;
	while (op != stop)
	{
		switch (op)
		{
		case addNewSoldier:add(vec);  //äåñôú çééì çãù	
			break;

		case medalList:medal(vec);  //äãôñú ôøèé äæëàéí ìöì"ù
			break;

		case mostSociometric:   //äãôñú ùí ä÷öéï áòì öéåï ñåöéåîèøé âáåä áéåúø 
			try {
				Soldier* s = mostSociometricScore(vec);
				if (s != nullptr) {
					cout << "Officer soldier with most sociometric score: ";
					cout << s->getFname() << " " << s->getName() << endl;
				}
			}
			catch (char* str) { cout << str; }			
			break;
		case countMedalPrivate:  
			cout << "# private soldier for medal: " << countMedal(vec);
			cout << endl;
			break;
		case noCombatCommander: cout << "list of no combat commander soldier:";
			noCombat(vec);
			cout << endl;
			break;
		case overSoldier:
			if (moreThan15(vec)) // ÷ééí çééì ùäùúúó éåáúø î- 15 îáöòéí öáàééí
				cout << "there is a soldier that takes more than 15 operations\n";
			else cout << "no soldier takes more than 15 operations\n";
			break;
		case removeOfficer:
			removeNoOper(vec);//îçé÷ä îäåå÷èåø/øùéîä ùì ëì äçééìí ÷öéðéí ùàéðí äùúúôå ëìì áîáöòéí öáàééí
			break;
		};
		cout << "enter 0-7\n";
		cin >> op;
	}
	return 0;
} 

/*
enter 0-7
1
enter 1 to add a private soldier
enter 2 to add a commander soldier
enter 3 to add a officer soldier
1
enter id, first name, last name and number Of operations
111 aaa aaa 3
enter 3 grades
100 95 98
enter 0-7
1
enter 1 to add a private soldier
enter 2 to add a commander soldier
enter 3 to add a officer soldier
2
enter id, first name, last name and number Of operations
222 bbb bbb 0
enter 1 if the soldier is combat and 0 if not
1
enter 0-7
1
enter 1 to add a private soldier
enter 2 to add a commander soldier
enter 3 to add a officer soldier
3
enter id, first name, last name and number Of operations
333 ccc ccc 0
enter number of sociometric score
100
enter 0-7
3
Officer soldier with most sociometric score: ccc ccc
enter 0-7
4
# private soldier for medal: 0
enter 0-7
5
list of no combat commander soldier :
enter 0-7
6
no soldier takes more than 15 operations
enter 0-7
7
private
ID: 111
first name: aaa
last name: aaa
num operations: 3
grades: 100 95 98
ID: 222
first name: bbb
last name: bbb
num operations: 0
grades:
combat: yes
enter 0-7
0

*/