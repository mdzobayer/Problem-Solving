#include <iostream>
#include <sstream>
using namespace std;

// Base Class
class Employee {
    private:
        string name;
        double pay;
    public:
        Employee() {    //default constractor
            name = "";
            pay = 0;
        };
        Employee(string empName, double payRate) {    //Complete Constractor
            name = empName;
            pay = payRate;
        };
        string getName(){
            return name;
        }
        void setName(string empName) {
            name = empName;
        }
        double getPay(){
            return pay;
        }
        void setPay(double payRate) {
            pay = payRate;
        }
        string toString() {
            //return name + ": " pay;
            stringstream stm;
            stm << name << ": " << pay;
            return stm.str();
        }
};
// Derived Class

class Manager : public Employee {
    private:
        bool salaried;
    public:
        Manager(string name, double payRate, bool isSalaried)
            : Employee(name, payRate) {
                salaried = isSalaried;
            }
        bool getSalaried() {
            return salaried;
        }
};
int main(){
    Employee emp1("Jane Smith", 15.00);
    cout << "Employee name: " << emp1.getName() << endl;
    cout << "Employee pay rate: " << emp1.getPay() << endl;
    Manager emp2("Bob Brown", 1500, true);
    cout << "Employee name: " << emp2.getName() << endl;
    cout << "Employee pay rate: " << emp2.getPay() << endl;
    cout << "Em2 Salaried ? " << emp2.getSalaried() << endl;
    return (0);
}

