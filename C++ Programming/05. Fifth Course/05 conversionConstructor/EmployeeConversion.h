#pragma once
#include <string>

using namespace std;

enum class gender {Male, Female, Unknown};

class EmployeeConversion
{
public:
    EmployeeConversion() = delete;
    EmployeeConversion(string nam, int ag, gender sx, int empno);
    string GetName() const;
    int GetEmpNo() const;
    gender GetSex() const;
    int GetAge() const;
private:
    string name;
    int age;
    gender sex;
    int employeeNumber;
};
