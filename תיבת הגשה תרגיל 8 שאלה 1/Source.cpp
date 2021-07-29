//Aviad Klein ID 315552679
//Exercise 8.1
//Sadna c++
//the program translate a mathematical expression from infix to postfix and inverse

#include<iostream>
#include"string"
#include"cstring"

#include "Vector.h"
#include "StackVector.h"

using namespace std;
string infixToPostfix(string str) {
	string my;
	Stack* stk1 = new StackVector();
	char ch, tav;
	int i = 0;
	ch = str[i++];
	while (ch != '\0')
	{
		if (ch == '(') {
			stk1->push(ch);
			ch = str[i];
			i++;
		}
		else if (ch == ')')
		{
			while (stk1->top() != '(')
			{
				my += stk1->pop();
				my += " ";

			}
			stk1->pop();
			ch = str[i];
			i++;
		}
		else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
		{
			stk1->push(ch);
			ch = str[i];
			i++;
		}
		else {
			while (ch >= '0' && ch <= '9') {
				my += ch;
				ch = str[i];
				i++;
			}
			my += " ";
		}
	}
	while (!stk1->isEmpty()) {
		my += stk1->pop();
		my += " ";
	}
	delete stk1;
	return my;
}
int calcPostfix(string str) {
	Stack* stk = new StackVector();
	int i = 0;
	float x, y, sum = 0;
	while (str[i] != '\0') {
		while (str[i] >= '0' && str[i] <= '9') {
			x = (float)(str[i] - '0');
			while (str[i + 1] != ' ') {
				x = x * 10 + (float)(str[i + 1] - '0');
				i++;
			}
			stk->push(x);
			i += 2;
		}
		y = stk->pop();
		x = stk->pop();
		if (str[i] == '+') stk->push(x + y);
		if (str[i] == '-') stk->push(x - y);
		if (str[i] == '*')  stk->push(x * y);
		if (str[i] == '/')  stk->push(x / y);
		i += 2;
	}
	sum = stk->pop();
	delete stk;
	return sum;
}
int main()
{
	string exp;
	cout << "enter an infix expression as a string" << endl;
	cin >> exp;
	string postfix = infixToPostfix(exp);
	cout << postfix << endl;
	cout << calcPostfix(postfix) << endl;
	return 0;
}
/*
output:
enter an infix expression as a string
(5+3)*((20/10)+(8-6))
5 3 + 20 10 / 8 6 - + *
32
*/
