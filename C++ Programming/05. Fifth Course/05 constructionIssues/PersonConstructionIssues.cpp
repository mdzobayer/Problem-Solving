#include "PersonConstructionIssues.h"
#include <string.h>


PersonConstractionIssues::PersonConstractionIssues()
{
    name = new char[10];
    strcpy(name, "Anonymous");
}
PersonConstractionIssues::PersonConstractionIssues(char* nam)
{
    int numchars = strlen(nam);
    name = new char[numchars + 1];
    strcpy(name,nam);
}
PersonConstractionIssues::~PersonConstractionIssues()
{
    delete [] name;
}

char* PersonConstractionIssues::GetName() const
{
    return name;
}
