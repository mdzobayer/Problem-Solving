#pragma once
#ifndef EMPLOYEE_DEFINED
#define EMPLOYEE_DEFINED
#include <string>
using namespace std;

class Employee {
public:     // functions
    // Modifier Functions
    Employee();             //default constructor
    Employee(string name, int empno, int ext);  //overloaded constructor
    void SetName(string name);
    void SetEmpNo(int empno);
    void SetExtension(int ext);
    // Query Functions
    string GetName() const;
    int GetEmpNo() const;
    int GetExtension() const;
protected:  // functions
private:    // functions
public:     // data (avoid wherever possible)
protected:  // data (only used in class hierarchies & inheritances)
private:    // data
    string name{"Unknown"};
    int employeeNo;
    int extension{ 0 };
};

#endif // EMPLOYEE_DEFINED
