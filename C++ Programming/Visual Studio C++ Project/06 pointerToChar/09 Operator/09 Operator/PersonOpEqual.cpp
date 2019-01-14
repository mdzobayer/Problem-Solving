#include "PersonOpEqual.h"
#include <string>

PersonCC::PersonCC()		// default constuctor
{
	name = new char[10];
	strcpy_s(name, 10, "Anonymous");
}

PersonCC::PersonCC(char* nam) // overloaded constructor
{
	int numchars = strlen(nam) + 1;
	name = new char[numchars];
	strcpy_s(name, numchars, nam);
}

PersonCC::PersonCC(const PersonCC& p)	// copy constuctor
{
	int numchars = strlen(p.name) + 1;
	name = new char[numchars];
	strcpy_s(name, numchars, p.name);
}

PersonCC::~PersonCC()	// destructor
{
	delete[] name;
}

char* PersonCC::GetName() const	// query functions
{
	return name;
}

PersonCC& PersonCC::operator = (const PersonCC& rhs) // assignment
{
	if (this != &rhs)
	{
		delete[] name;
		int numchars = strlen(rhs.name) + 1;
		name = new char[numchars];
		strcpy_s(name, numchars, rhs.name);
	}
	return *this;
}