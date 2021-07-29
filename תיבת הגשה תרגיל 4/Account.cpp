#include "Account.h"
#include <string>

int Account::sumWithdraw = 0;//static initialization
int Account::sumDeposit = 0;

 Account ::Account()// d constructor
{
	 accountNumber=0;
	 code=0;
	 balance=0;
	 mail.clear();
}
 Account::Account(int acc, int cod, int bal, string em)// constructor
 {
	 accountNumber = acc;
	 balance = bal;
	 this->set_mail(em);
	 try {
		 if ((cod < 1000) || (cod > 9999))throw 1;//valid code
	 }
	 catch (int i)
	 {
		 cout << "ERROR: wrong code!";
		 return;
	 }
	 code = cod;
 }

 void Account:: set_mail(string email)
 {
	

		 if (!(email.find('@') < email.length())) throw "ERROR: email must contain @!\n";//valid for @

		 int x=0;//valid for ending
		 x = email.find(".com");
		 if (x == -1)
		 {
			 int y = 0;
			 y = email.find(".co.il");
			 if (y == -1) throw "ERROR: email must end at .com or .co.il\n";
		 }

		 for (int i = 0; i < email.length(); i++)// valid ' '
		 	 if (isspace(email[i])) throw "ERROR: email must end at .com or .co.il\n";
		 
	 mail = email;
 }


 istream& operator>>(istream& is, Account& a)
 {
	int co;
	string mail;
	is >>a.accountNumber>>co >>mail;
	if (co > 9999 || co < 1000) throw "ERROR: code must be of 4 digits!";
	a.code = co;
	a.set_mail(mail);
	a.balance = 0;
	
		 return is;
 }
 void Account ::withdraw(int nis)
 {	
	if (balance - nis < -6000 || (balance - nis < -6000 && nis > 2500)) {  // àñåø îéðåñ éåúø î 6000
		throw "ERROR: cannot have less than - 6000 NIS!\n";
	}
	else if (nis > 2500) {//àñåø ìîùåê éåúø î 2500 ùç
		throw "ERROR: cannot withdraw more than 2500 NIS!\n";
	}

	balance -= nis;
	sumWithdraw += nis;
	return;
 }
 void Account::deposit(int check)
 {
	if (check > 10000 || check < 0) throw "ERROR : cannot deposit more than 10000 NIS!";// exeptions
	balance += check;
	sumDeposit += check;
	return;
 }

