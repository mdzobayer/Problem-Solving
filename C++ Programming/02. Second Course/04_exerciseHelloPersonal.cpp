#include <iostream>

using namespace std;
int main(){
    string firstName;
    firstName = "Michael";
    cout << "Hello " << firstName <<endl;
    string middleName, lastName;
    middleName = "Mason";
    lastName = "McMillan";
    cout << "Hello " <<firstName << " " <<middleName
         << " " << lastName << endl;
    int age = 53;
    string fullName = firstName + " " + middleName + " " + lastName;
    cout << "Hello, " << fullName << endl;
    cout << "You are " << age << " Years old" << endl;
    cout << "Next year you will be ";
    cout << age + 1 << " Years old" <<endl;
    return (0);
};
