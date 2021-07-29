#include "Family.h"

Family::Family()
{
	key = 0;
	for (int i = 0; i < 20; i++)
		familyName[i] = NULL;
	familyMembers = 0;
	phone = 0;
	for (int i = 0; i < 6; i++)
		classes[i] = false;
	
}

void Family::setClasses(bool* classes_)
{
	for (int i = 0; i < 6; i++)
		classes[i] = classes_[i];
}

istream& operator>>(istream& in, Family& fm)
{
	in >> fm.key >> fm.familyName >> fm.familyMembers >> fm.phone;
	return in;
}
