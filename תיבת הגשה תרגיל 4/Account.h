#pragma once
#include <string>
#include <iostream>
using namespace std;

class Account
{
private:
	int accountNumber;
	long int code;
	int balance;
	string mail;

	static int sumWithdraw;
	static int sumDeposit;
public:
	Account();
	Account(int, int, int, string);

	void set_bal(int x) { balance = x; }
	void set_mail(string);
	int getAccountNumber() { return accountNumber; }
	long int getCode() { return this->code; }
	int getBalance() { return balance; }
	string get_mail() { return mail; }

	friend istream& operator>>(istream& ,Account&);
	void withdraw(int );
	void deposit(int);

	int getSumWithdraw() { return Account::sumWithdraw; }
	int getSumDeposit() { return Account::sumDeposit; }


};



