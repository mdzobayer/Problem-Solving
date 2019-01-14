#include <iostream>
#include <sstream>
using namespace std;
/*
Destructor are used to clean up any sort of resources
 allocation thats been made one an object is deleted
 from a program. We are going to look at destructor
 and more detail later in the course. But this is a
 good time to introduce the syntax for creating them.
 A destructor is similar to a constructor that uses
 the same name as the class except put a tild(~) before
 it.

The destructor called automatically. You don't have to
 make a call to the destructor.It will be call
 automatically when a object is deleted from a program.
*/
// Base Class
class Employee {
    protected:
        string name;
        double pay;
    public:
        Employee() {    //default constructor
            name = "";
            pay = 0;
        };
        Employee(string empName, double payRate) {    //Completer Constractor
            name = empName;
            pay = payRate;
        };
        ~Employee() {
            //do something here
        }
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
        double grossPay(int hours) {
            return pay * hours;
        }
};
// Derived Class

class Manager : public Employee {
    private:
        bool salaried;
    public:
        //Default Constructor
        Manager() : salaried(true) { } //salaried set default true value
        //----Completer Constructor----
        Manager(string name, double payRate, bool isSalaried)
            : Employee(name, payRate){
                salaried = isSalaried;
        };
        //---------Destructor---------
        ~Manager() {
            //Free allocated resources
        }
        bool getSalaried() {
            return salaried;
        };
        double grossPay(int hours) {
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
    Employee emp1("Jane Smith", 15.00);
    cout << "Employee name: " << emp1.getName() << endl;
    cout << "Employee pay rate: " << emp1.getPay() << endl;
    cout << "Employee gross pay: " << emp1.grossPay(40) << endl;
    //cout << "Employee pay rate: " << emp1.pay << endl;
    Manager emp2("Bob Brown", 1500, true /* / false */);

    cout << emp2.toString();
    cout << "emp2's gross pay: " << emp2.grossPay(100);
    return (0);
};

