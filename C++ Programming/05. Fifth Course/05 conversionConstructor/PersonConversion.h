#pragma once
#include <string>
using namespace std;
#include "EmployeeConversion.h"
class PersonConversion {
public:
    PersonConversion(char* nam, int ag, char sx);
    PersonConversion(const EmployeeConversion& e);
private:
    string name;
    int age;
    char sex;
};
