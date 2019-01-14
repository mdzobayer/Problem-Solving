#pragma once
#include <string>
using namespace std;
#include "EmployeeExplicit.h"

class PersonExplicit
{
public:
    PersonExplicit(char* nam, int ag, char sx);
    explicit PersonExplicit(const EmployeeExplicit& e);
private:
    string name;
    int age;
    char sex;
};
