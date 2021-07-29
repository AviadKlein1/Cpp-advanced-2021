//Aviad Klein ID 315552679
// Sadna C++
// exersice 4
// Program for Bank Account

#include <iostream>
#include "Clock.h"
#include "Account.h"

using namespace std;

enum action
{
	stop,
	balance,
	deposit,
	withdraw,
	sumDeposit,
	sumWithdraw
};
action menu()
{
	cout << "enter 1 to get account balance" << endl;
	cout << "enter 2 to deposit money" << endl;
	cout << "enter 3 to withdraw money" << endl;
	cout << "enter 4 to see the sum of all withdraws" << endl;
	cout << "enter 5 to see the sum of all Deposits" << endl;
	cout << "enter 0 to stop" << endl;
	int x;
	cin >> x;
	return (action)x;
}
int findAccount(Account* bank, int size)
{
	int number, code;
	cout << endl << "please enter account number: " << endl;
	cin >> number;
	int i = 0;
	while (i < size && bank[i].getAccountNumber() != number)
		i++;
	if (i == 10)
		throw "ERROR: no such account number\n";
	cout << "please enter the code: " << endl;
	cin >> code;
	if (bank[i].getCode() == code)
		return i;
	else
		throw "ERROR: wrong code!";
}
void printTransaction(Account a, action ac, Clock& c)
{
	cout << c << "\t";
	;
	switch (ac)
	{
	case balance: cout << "account #: " << a.getAccountNumber() << "\t";
		cout << "balance: " << a.getBalance() << endl;
		break;
	case deposit:
	case withdraw: cout << "account #: " << a.getAccountNumber() << "\t";
		cout << "new balance: " << a.getBalance() << endl;
		break;
	case sumDeposit:
		cout << "sum of all deposits: " << a.getSumDeposit() << endl;
		break;
	case sumWithdraw:
		cout << "sum of all withdraws: " << a.getSumWithdraw() << endl;
		break;
	}
}
void getBalance(Account* bank, int size, Clock& c)
{
	int i = findAccount(bank, size);
	c += 20;
	printTransaction(bank[i], balance, c);
}
void cashDeposit(Account* bank, int size, Clock& c)
{
	int i = findAccount(bank, size);
	float amount;
	cout << "enter the amount of the check:\n";
	cin >> amount;
	bank[i].deposit(amount);
	c += 30;
	printTransaction(bank[i], deposit, c);
}
void cashWithdraw(Account* bank, int size, Clock& c)
{
	int i = findAccount(bank, size);
	float amount;
	cout << "enter the amount of money to withdraw:\n";
	cin >> amount;
	bank[i].withdraw(amount);
	c += 50;
	printTransaction(bank[i], withdraw, c);
}
int main()
{

	Clock c(8, 0, 0);
	Account bank[10];		
	cout << "enter account number, code and email for 10 accounts:\n";

	for (int i = 0; i < 10; i++)
	{
		try {
			cin >> bank[i];
			for (int j = 0; j < i; j++)
				if (bank[i].getAccountNumber() == bank[j].getAccountNumber())
					throw "ERROR: account number must be unique!\n";
		}
		catch (const char* msg)
		{
			cout << c << '\t' << msg;
			i--;
		}
	}


	action ac = menu();
	while (ac)
	{
		try {
			switch (ac)
			{
			case balance: getBalance(bank, 10, c);
				break;
			case withdraw:cashWithdraw(bank, 10, c);
				break;
			case deposit:cashDeposit(bank, 10, c);
				break;
			case sumDeposit:c += 60;
				printTransaction(bank[0], sumDeposit, c);
				break;
			case sumWithdraw:c += 60;
				printTransaction(bank[0], sumWithdraw, c);
			}
		}
		catch (const char* msg) {
			cout << c << '\t' << msg;
		}
		ac = menu();
	}
	return 0;
}

/*
enter account number, code and email for 10 accounts:

{{{ example: 2213452; 1111, asd@gmail.com }}}

enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all withdraws
enter 5 to see the sum of all Deposits
enter 0 to stop

please enter account number:
please enter the code:
enter the amount of the check:
08:00:30        account #: 4    new balance: 5000
enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all withdraws
enter 5 to see the sum of all Deposits
enter 0 to stop

please enter account number:
please enter the code:
enter the amount of money to withdraw:
08:00:30        ERROR: cannot withdraw more than 2500 NIS!
enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all withdraws
enter 5 to see the sum of all Deposits
enter 0 to stop

please enter account number:
please enter the code:
08:00:50        account #: 4    balance: 5000
enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all withdraws
enter 5 to see the sum of all Deposits
enter 0 to stop

*/