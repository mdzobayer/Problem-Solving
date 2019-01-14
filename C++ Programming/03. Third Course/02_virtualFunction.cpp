#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

// Base Class
class Employee {
    protected:
        string name;
        double pay;
    public:
        Employee() {    // Default constructor
            name = "";
            pay = 0;
        };
        Employee(string empName, double payRate) {    // Complete constructor
            name = empName;
            pay = payRate;
        };
        string getName(){
            return name;
        };
        void setName(string empName) {
            name = empName;
        }
        double getPay(){
            return pay;
        };
        void setPay(double payRate) {
            pay = payRate;
        };
        string toString() {
            //return name + ": " pay;
            stringstream stm;
            stm << name << ": " << pay;
            return stm.str();
        };
        virtual double grossPay(int hours) {
            return pay * hours;
        }
};
// Derived Class

class Manager : public Employee {
    private:
        bool salaried;
    public:
        Manager(string name, double payRate, bool isSalaried)
            : Employee(name, payRate) { //calling base constructor / class code
                salaried = isSalaried;
        };
        bool getSalaried() {
            return salaried;
        };
        virtual double grossPay(int hours) {
            if (salaried) {
                return pay;
            }
            else {
                return pay * hours;
            }
        }

        string toString() {
            //return name + ": " pay;
            string salary;
            stringstream stm;
            if (salaried) {
                salary = "Salaried";
            }
            else {
                salary = "Hourly";
            }
            stm << name << ": " << pay
                << ": " << salary << endl;
            return stm.str();
        };
};
int main(){

    Employee emp1("Jane Smith", 25.00);
    Manager mgr1("Bob Brown", 1200, true);
    Employee *empPtr;
    empPtr = &emp1;
    cout << "Name: " << empPtr->getName() << endl;
    cout << "Play: " << empPtr->grossPay(40) << endl;
    empPtr = &mgr1;
    cout << "Name: " << empPtr->getName() << endl;
    cout << "Play: " << empPtr->grossPay(40) << endl;
    vector<Employee*> employees;
    employees.push_back(&emp1);
    employees.push_back(&mgr1);
    for(int i = 0; i < employees.size(); ++i) {
        cout << "Name: " << employees[i]->getName() << endl;
        cout << "Pay: " << employees[i]->grossPay(40) << endl;
    }
    return (0);
};
