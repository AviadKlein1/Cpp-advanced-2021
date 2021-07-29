//Aviad klein ID 315552679
//Sadna c++
// Exs 9.2
//program for store books in library

#include <iostream>
#include <string>
#include "Tree.h"
#include "book.h"
#include "SearchTree.h"

using namespace std;

enum { a=97,b,c,d,e };
int main()
{
	Tree<book>* Lib = new SearchTree<book>;
	
	char x;
	cout << "enter a-e:\n";
	cin >> x;
	while (x != e)
	{
		book newBook;
		switch (x)
		{
		case a: 
			cout << "enter a book:\n ";
			cin >> newBook;
			Lib->add(newBook);
			break;

		case b: 
			try
			{
				cout << "enter a book:\n ";
				cin >> newBook;
				if (!(Lib->search(newBook)))cout << "no exist " << endl;
				Lib->remove(newBook);
			}
			catch (const char* str)
			{
				cout << str << endl;
			}

			break;

		case c:
			cout << "enter a book:\n ";
			cin >> newBook;
			if (Lib->search(newBook))cout << "exist " << endl;
			else cout << " no exist " << endl;
			break;

		case d:
			//print a-b-c
			 Lib->inOrder();
			break;


		case e:
			return 0;

		default:
			cout << "error\n";
		}
		cout << "enter a-e:\n";
		cin >> x;
	}
	return 0;
}



/*enter a-e:
a
enter a book:
2 b b
enter a-e:
a
enter a book:
5 e e
enter a-e:
a
enter a book:
1 a a
enter a-e:
a
enter a book:
4 d d
enter a-e:
a
enter a book:
7 g g
enter a-e:
a
enter a book:
3 c c
enter a-e:
b
enter a book:
5 e e
enter a-e:
d
1 a a
2 b b
3 c c
4 d d
7 g g
enter a-e:
e
*/