//Aviad Klein ID 315552679
//SADNA c++
//Exercise 3.3
//The progrem take care on strings 

#include <iostream>
#include "myString.h"

#define _CRT_SECURE_NO_DEPRECATE
#pragma warning(disable : 4996)

int main()
{
	char a1[100];
	char b1[100];
	cin >> a1;
	cin >> b1;
	int n;
	cin >> n;
	myString a(a1), b(b1);
	myString c(a1), d(b1);


	
	for (int i = 0; i < strlen(c.getString()); i++)
	{
		if (c[i] - d[i] == 32) c[i] = (c[i] - 32);
		if (d[i] - c[i] == 32) d[i] = (d[i] - 32);
	}
	if (c > d)
		cout << "a>b" << endl;
	if (c = d)
		cout << "a=b" << endl;
	if (c < d)
		cout << "a<b" << endl;

	if (n > strlen(b.getString()))
	{
		cout << "ERROR\n";
		if(c = d)	return 0;
	}
	else
		cout << (b.insert(a.getString(), n)).getString() << endl;

	char tav;
	int index;
	cin >> tav;
	cin >> index;

	myString replace(b.insert(a.getString(), n));
	replace[index] = tav;
	cout << replace.getString();

	return 0;
}
/*
World
Hello
5
a>b
HelloWorld
!
5
Hello!orld
*/