#include "PersonDeletedCC.h"
#include <string.h>

PersonDeletedCC::PersonDeletedCC()
{
    name = new char[10];
    strcpy(name, "Anonymous");
}
PersonDeletedCC::PersonDeletedCC(char* nam)
{
    name = new char[strlen(nam) + 1];
    strcpy(name, nam);
}
PersonDeletedCC::~PersonDeletedCC()
{
    delete []name;
}
char* PersonDeletedCC::GetName()const
{
    return name;
}
