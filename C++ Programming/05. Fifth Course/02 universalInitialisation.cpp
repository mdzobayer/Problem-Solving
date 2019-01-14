#include <iostream>
#include <vector>

using namespace std;
struct date{
    int dd;
    int mm;
    int ccyy;
};
class Employee {
public:
    // Default Constructor
    Employee()
        : salary(0.0), empNumber(0)
    {

    }
    // Overloaded Constructor
    Employee(double sal, int eno )
        : salary(sal), empNumber(eno)
    {

    }
private:
    double salary;
    int empNumber;
};
class UniversalEmployee {
public:
    // Default Constructor
    UniversalEmployee()
        : salary{ 0.0 }, empNumber{ 0 }
    {

    }
    // Overloaded Constructor
    UniversalEmployee(double sal, int eno )
        : salary{ sal }, empNumber{ eno }
    {

    }
private:
    double salary = 0.0;
    int empNumber;
};

int main() {

    // The next two lines show fundamentals initializations
    int a = 0;
    int b(0);

    // The next line shows universal initialization of fundamentals types
    int c{ 0 }; // universal initialization syntax

    // The next four lines show initialization of arrays and structs
    int number1[5] = {0,1,2,3,4};
    int number2[] = {1,2,3,4,5};
    int number3[10] = { 0 };
    date millennum = { 1,1,2000 };

    // The next four lines show universal initialization of arrays and structs
    int number4[5]{ 0,1,2,3,4 };
    int number5[]{ 1,2,3,4,5 };
    int number6[10]{ 0 };
    date firstMillennium{ 1,1,2000 };

    // The next two lines show initialization of objects of class Employee
    Employee worker1;
    Employee worker2(2000.00, 1234);

    // The next two lines show universal initialization of objects of class Employee
    Employee worker3{};
    Employee worker4{ 2000.00, 1234 };

    // The next line shows vector initialization
    vector<int> digits1(3, 999);

    // The next line shows vector universal initialization
    vector<int> digits2{ 999,999,999 };

    return (0);
}
