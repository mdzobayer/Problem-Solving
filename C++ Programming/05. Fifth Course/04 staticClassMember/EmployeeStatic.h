#pragma once
class EmployeeStatic
{
public:
    EmployeeStatic();
    int GetEmpNo();
private:
    // class member variable - created on instantiation
    int empNo;
    // placeholder - no storage created on instantiation
    static int lastEmpNo;
};
