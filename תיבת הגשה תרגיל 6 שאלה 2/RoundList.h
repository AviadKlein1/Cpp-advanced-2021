#pragma once
#include<iostream>
using namespace std;
#include"List.h"

class RoundList : public List
{
public:
	RoundList();
	~RoundList();
	void addToEnd(int val);
	int search(int n);
	void add(int value);
	void clear();
	void removeFirst();

};