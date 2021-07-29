//Aviad klein ID 315552679
//Sadna c++
//Exs 11
//The program manages the registration system of children in classes at their neighborhood



#include <iostream>
#include <fstream>
#include "Family.h"
#include <queue>
#include<cstring>

using namespace std;

void setFile(fstream& f)
{
	Family stam; //empty object with id=0, name = NULL
	for (int i = 0; i < 100; i++)
		f.write((char*)&stam, sizeof(Family));
}
void checkNum(int snum) {
	if (snum < 1 || snum>100)
		throw "ERROR: Invalid family number";
}
void add(fstream& f)
{
	Family fm;
	Family temp;
	cin >> fm;
	if (fm.getKey() > 100 || fm.getKey() < 1)throw "ERROR: Invalid family number";//בדיקה אם הערך גדול מ100 או קטן מ1
	//f.open("families.txt");
	//f.seekg(ios:: beg); // סמן קריאה בהתחלה

	f.seekg((fm.getKey() - 1) * sizeof(Family));
	f.read((char*)&temp, sizeof(Family));
	if (temp.getKey() == fm.getKey())
		throw "ERROR: Family is already in the file";

	//f.read((char*)&temp, sizeof(Family));//קריאה מהקובץ לטמפ
	//while (!f.eof())//לא בסוף
	//{ 
	//	if(temp.getKey() == fm.getKey())throw "ERROR: Family is already in the file"; //קיים כבר
	//	//f.seekg((4)*sizeof(Family));
	//	f.read((char*)&temp, sizeof(Family)); // קרא את הבא
	//}
	/*f.seekg((snum - 1) * sizeof(Family));
	f.read((char*)&s, sizeof(Family));
	if (s.num == num1)
		throw "ERROR: Student is already in the file";*/

	f.seekp((fm.getKey() - 1) * sizeof(Family));
	f.write((char*)&fm, sizeof(Family));


	//f.seekg(ios::beg);
	//f.seekp(ios::beg);

	//f.read((char*)&temp, sizeof(Family));
	//while (!f.eof())
	//{
	//	if (temp.getKey() == 0)// אם הגענו למשפחה ריקה נכתוב
	//	{
	//		f.write((char*)&fm, sizeof(Family));
	//		break;
	//	}
	//	//f.seekp((4)*sizeof(Family));
	//}
	//f.close();
	////חיפוש ע"י קידום המצביע לקריאה כל פעם בסייזאוף
}
void del(fstream& f, int snum)
{
	Family temp;
	if (snum > 100 || snum < 1)throw "ERROR: Invalid family number";//validation
	f.seekp((snum - 1) * sizeof(Family), ios::beg);// לא דרשו לבדוק האם ישנו מספר כזה למחוק.
	f.write((char*)&temp, sizeof(Family)); // replace snum in temp
}
void update(fstream& f, int snum, queue<Family>& q)
{
	Family temp;
	bool flag = false;
	if (snum < 1 || snum>100)
		throw "ERROR: Invalid family number";;
	
	f.seekg(ios:: beg); // סמן קריאה בהתחלה
	//f.read((char*)&temp, sizeof(Family));//קריאה מהקובץ לטמפ
	//while (!f.eof())//לא בסוף
	//{
	//	if (temp.getKey() == snum) {
	//		flag = true;
	//		break;
	//	}
	//	f.read((char*)&temp, sizeof(Family)); // קרא את הבא
	//}
	f.seekg((snum - 1) * sizeof(Family));
	f.read((char*)&temp, sizeof(Family));
	if (temp.getKey() != snum)throw "ERROR: Family is not in the file";// validation

	cout << "enter 1 0r 0 to classes 1-6:\n";
	bool classesfm[6];// מערך החוגים של המשפחה
	for (int i = 0; i < 6; i++)
		cin >> classesfm[i];

	int membersAtClass[6];// מערך לשמירת כמות המשתתפים בחוג
	f.seekg(ios::beg);
	f.read((char*)&temp, sizeof(Family));
	while (!f.eof())//לא בסוף
	{
		for (int i = 0; i < 6; i++)
			if(temp.getClasses()[i]) membersAtClass[i]++; // השמה של מספר התלמידים בכל חוג
		f.read((char*)&temp, sizeof(Family)); // קרא את הבא
	}

	bool classesforWrite[6] = { false, false, false, false, false, false };
	bool classesforQueue[6] = { false, false, false, false, false, false };

	for (int i = 0; i < 6; i++)
	{
		if (membersAtClass[i] > 9 && classesfm[i])classesforQueue[i] = true; // המשפחה רוצה להכנס לחוג מלא
		else if (membersAtClass[i] >= 9 && classesfm[i])classesforWrite[i] = true;// החוג פנוי
	}

	temp.setClasses(classesforWrite);// הכנסת החוגים למשפחה טמפ
	f.seekp((snum - 1) * sizeof(Family)); // כתיבת החוגים של המשפחה לקובץ
	f.write((char*)&temp, sizeof(Family));
	
	temp.setClasses(classesforQueue);// הכנסת החוגים בתוך המשפחה לרשימת המתנה
	q.push(temp);
}
void waiting(fstream& f, queue<Family>& q)
{
	//הוצאת המשפחה הראשונה מהתור ובדיקה של החוגים הרשומים אצלה כאמת. 
	//מעבר על כל המשפחות בקובץ והוצאה של מערך כמות הרשומים בחוגים
	//בדיקת המשפחה לעומת החוגים
	//עדכון בקובץ
	// עדכון המשפחה לתור, הכנסה לתור חדש שיחזור 

	Family fromQ;
	Family temp;
	queue<Family> newq;
	fromQ = q.front();
	q.pop();
	while (!q.empty()) {
		int membersAtClass[6];// מערך לשמירת כמות המשתתפים בחוג
		f.seekg(ios::beg);
		f.read((char*)&temp, sizeof(Family));
		while (!f.eof())//לא בסוף
		{
			for (int i = 0; i < 6; i++)
				if (temp.getClasses()[i]) membersAtClass[i]++; // השמה של מספר התלמידים בכל חוג
			f.read((char*)&temp, sizeof(Family)); // קרא את הבא
		}


		bool classesforWrite[6] = { false, false, false, false, false, false };
		bool classesforQueue[6] = { false, false, false, false, false, false };
		char tav;
		for (int i = 0; i < 6; i++)
		{
			if (fromQ.classes[i] && membersAtClass[i] >= 9)
			{
				cout << fromQ.familyName << fromQ.phone << endl;
				cout << "update family to txt? enter Y or N:\n";
				cin >> tav;
				if(tav == 'Y')classesforWrite[i] = true;
			}
			else if (fromQ.classes[i] && membersAtClass[i] > 9)classesforQueue[i] = true;
		}

		temp.setClasses(classesforWrite);// הכנסת החוגים למשפחה טמפ
		f.seekp((temp.key - 1) * sizeof(Family));
		f.write((char*)&temp, sizeof(Family));
		
		temp.setClasses(classesforQueue);// הכנסת החוגים בתוך המשפחה לרשימת המתנה
		newq.push(temp);
	}
	q = newq;
}

bool rishum(fstream& f, int snum, int cnum) {
	checkNum(snum);
	Family temp;

	f.seekg((snum - 1) * sizeof(Family));
	f.read((char*)&temp, sizeof(Family));
	if (temp.key != snum) throw "ERROR: Student is not in the file";
	if (cnum < 1 || cnum > 6) throw "ERROR: Invalid student number";

	if (temp.classes[cnum])
		return true;
	return false;
}

void print(fstream& f, int snum) {
	checkNum(snum);
	Family temp;
	f.seekg((snum - 1) * sizeof(Family));
	f.read((char*)&temp, sizeof(Family));
	if (temp.getKey() != snum)throw "ERROR: Family is not in the file";
	cout << temp.familyName << " " << temp.familyMembers << " " << temp.phone <<" ";
	for (int i = 0; i < 5; i++) {
		if (temp.classes[i])
			cout << "Y ";
		else cout << "N ";
	}
	cout << endl;
}
void inClass(fstream& f, int cnum) {
	if (cnum < 1 || cnum>6)throw "ERROR: Invalid classe number";
	Family temp;
	f.read((char*)&temp, sizeof(Family));
	while (!f.eof()) {
		if (temp.classes[cnum])print(f, temp.key);
		f.read((char*)&temp, sizeof(Family));
	}
}

int main()
{
	queue<Family> q;
	fstream file;
	file.open("families.txt", ios::binary | ios::in | ios::out);
	if (!file)
	{
		cout << "ERROR: couldn't open file\n";
		return 0;
	}
	setFile(file);
	int choice;
	int snum;
	int cnum;
	cout << "Choices are:\n0 to exit\n1 to add a family\n2 to delete a family\n3 to update rishum to classes\n4 to update waiting to classes \n5 to check rishum for a classas\n6 to print a family\n7 to print all the families that participate in a specific class\n";
	enum {EXIT,ADD,DEL,UPDATE,WAITING, RISHUM, PRINT, CLASS};
	cout << "enter 0-7:\n";
	cin >> choice;
	while (choice)
	{
		switch (choice)
		{
		case EXIT:
			file.close();
			return 0;
		case ADD://add to the file
			try { add(file); }
			catch (const char* msg) { cout << msg; }
			break;
		case DEL://delete from file
			cout << "enter number of family to delete:\n";
			cin >> snum;
			try { del(file, snum); }
			catch (const char* msg) { cout << msg; }
			break;
		case UPDATE://update the list of classes of a family
			cout << "enter number of family to update:\n";
			cin >> snum;
			try { update(file, snum, q); }
			catch (const char* msg) { cout << msg; }
			break;
		case WAITING://update the list of classes of a waiting family
			waiting(file, q);
			break;
		case RISHUM://check rishum to a specific class
			cout << "enter number of family to check rishum:\n";
			cin >> snum;
			cout << "enter number of class to check rishum:\n";
			cin >> cnum;
			try
			{
				cout << "The family is" << (rishum(file, snum, cnum) ? " " : " not ") << "taking the class\n";
			}
			catch (const char* msg) { cout << msg; }
			break;
		case PRINT://print the details of a specific family
			cout << "enter number of family to print:\n";
			cin >> snum;
			try { print(file, snum); }
			catch (const char* msg) { cout << msg; }
			break;
		case CLASS://print the details of all the families that are taking a specific class
			cout << "enter number of class to check rishum:\n";
			cin >> cnum;
			try { inClass(file, cnum); }
			catch (const char* msg) { cout << msg; }
			break;
		default:
			cout << "ERROR: invalid choice\n";

		}
		cout << "\nenter 0-7:\n";
		cin >> choice;
	}
	file.close();
	return 0;
}
