#include "EmployeeStatic.h"

// static variable
int EmployeeStatic::lastEmpNo = 10000;

EmployeeStatic::EmployeeStatic()
{
    empNo = ++lastEmpNo;
}

int EmployeeStatic::GetEmpNo()
{
    return empNo;
}
