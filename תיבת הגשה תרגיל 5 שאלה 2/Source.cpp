//Aviad Klein ID 315552679
//Sadna c++
//Exercise 5.2
// Implemetion of linked list

#include <iostream>
#include "List.h"
using namespace std;

List merge(List& L1, List& L2) {
	List l = L1;
	l.helpMerge(L2);
	return l;
}

void makeSet(List& L1) {
	L1.helpMakeSet();
}

List reverse(List& L1)
{
	return L1.helpReverse(L1);
	
}

int main()
{
	List lst1, lst2, mergedList, temp;

	cout << "enter sorted values for the first list:" << endl;
	cin >> lst1;
	cout << "enter sorted values for the second list:" << endl;
	cin >> lst2;

	mergedList = merge(lst1, lst2);
	cout << "the new merged list: " << mergedList << endl;

	makeSet(mergedList);
	cout << "the new merged set: " << mergedList << endl;

	temp = reverse(mergedList);
	cout << "the new merged reverse: " << temp << endl;


	return 0;
}

/*
enter sorted values for the first list :
6 5 4 3 2 1 9
enter sorted values for the second list :
7 5 4 3 9
the new merged list : 7 6 5 5 4 4 3 3 2 1
the new merged set : 7 6 5 4 3 2 1
the new merged reverse : 1 2 3 4 5 6 7
Press any key to continue . . .

*/