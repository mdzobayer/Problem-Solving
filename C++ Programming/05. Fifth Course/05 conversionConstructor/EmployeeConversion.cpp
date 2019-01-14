#include "EmployeeConversion.h"

EmployeeConversion::EmployeeConversion(string nam, int ag, gender sx, int empNo)
    : name{ nam }, age{ ag }, sex{ sx }, employeeNumber{ empNo } { };
string EmployeeConversion::GetName() const {
    return name;
}
int EmployeeConversion::GetAge() const {
    return age;
}
gender EmployeeConversion::GetSex() const {
    return sex;
}
int EmployeeConversion::GetEmpNo() const {
    return employeeNumber;
}
