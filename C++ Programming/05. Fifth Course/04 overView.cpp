#include <iostream>

using namespace std;

class Employee {
public:
    void SetName(string name);
    void SetEmpNo(int empno);
    void SetExtension(int ext);
    string GetName();
    int GetEmpNo();
    int GetExtension();

protected:  // functions
private:    // functions
public:     // data (avoid wherever possible)
protected:  // data (only used in class hierarchies & inheritance)

private:    // data
    string name;
    int employeeNo;
    int extension;
    string name;

};
int main() {

    return (0);
}
