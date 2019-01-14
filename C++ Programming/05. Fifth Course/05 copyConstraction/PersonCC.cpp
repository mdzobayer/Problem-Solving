#include "PersonCC.h"
#include <string.h>

// Default Constructor
PersonCC::PersonCC()
{
    name = new char[10];
    strcpy(name, "Anonymous");
}
// Overloaded Constructor
PersonCC::PersonCC(char* nam)
{
    int numberChars = strlen(nam) + 1;
    name = new char[numberChars];
    strcpy(name, nam);
}
// Copy Constructor
PersonCC::PersonCC(const PersonCC& p)
{
    int numChars = strlen(p.name) + 1;
    name = new char[numChars];
    strcpy(name, p.name);
}
// Destructor
PersonCC::~PersonCC()
{
    delete [] name;
}
// Query Function
char* PersonCC::GetName() const
{
    return name;
}

