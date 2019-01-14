#include "PersonDestructor.h"
#include <string.h>

PersonDestructor::PersonDestructor()
{
    name = new char[10];
    strcpy(name, "Anonymous");
}
PersonDestructor::PersonDestructor(char *nam)
{
    name = new char[strlen(name) + 1];
    strcpy(name, nam);
}
PersonDestructor::~PersonDestructor()
{
    delete[] name;
    // name goes out of the scope and gets destroyed here
}
void PersonDestructor::UsePerson()
{
    // use PersonDestructor object
}
