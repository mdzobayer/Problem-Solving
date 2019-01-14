#include "EmployeeOverview.h"
// Default constructor
Employee::Employee() = default;
    /*delete keyword is opposite of default keyword*/
    /*
    ------- Colon Initialization (Best Way) ---------
    :name("Unknown"), employeeNo{ 0 }, extension(0)
{
    ---------- Assignment Initialization ----------
    name = "Unknown";
    employeeNo = 0;
    extension = 0;
}*/
Employee::Employee(string n, int eno, int e)
    //---- Colon Initialization (Best Way) ----
    :name{ n }, employeeNo{eno}, extension{e}
{
    //------ Assignment Initialization -------
    /*name = n;
    employeeNo = eno;
    extension = e;*/
}
void Employee::SetName(string nam) {
    name = nam;
}
void Employee::SetEmpNo(int empno) {
    employeeNo = empno;
}
void Employee::SetExtension(int ext){
    extension = ext;
}
string Employee::GetName() const {
    return name;
}
int Employee::GetEmpNo() const {
    return employeeNo;
    //not allowed in constant function
    //employeeNo = 0;
}
int Employee::GetExtension() const{
    return extension;
}
