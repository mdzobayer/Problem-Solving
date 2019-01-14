#pragma once
#include <string>
using namespace std;

enum class gender{ Male, Female, Unknown };
class EmployeeExplicit
{
public:
    EmployeeExplicit() = delete;
    EmployeeExplicit(char* nam, int ag, gender sx, int empno);
    string GetName() const;
    int GetAge() const;
    gender GetSex() const;
    int GetEmpNo() const;
private:
    string name;
    int age;
    gender sex;
    int EmployeeNumber;
};

