#include "PersonCCRevisited.h"
#include <iostream>

PersonCC::PersonCC()		// default constuctor
{
	name = new char[10];
	strcpy_s(name, 10, "Anonymous");
}

PersonCC::PersonCC(char* nam) // overloaded constructor
{
	int numbers = strlen(nam) + 1;
	name = new char[numbers];
	strcpy_s(name, numbers, nam);
}

PersonCC::PersonCC(const PersonCC& p)
{
	int numchars = strlen(p.name) + 1;
	name = new char[numchars];
	strcpy_s(name, numchars, p.name);
}

PersonCC::~PersonCC()	// destructor
{
	delete[] name;
}