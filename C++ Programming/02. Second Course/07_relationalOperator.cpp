#include <iostream>

using namespace std;
int main(){
    string myPassword = "letmein";
    cout << (myPassword == "password") << endl;
    cout << (myPassword != "password") << endl;

    int hoursWorked = 41;
    cout << (hoursWorked > 40) << endl;
    cout << (hoursWorked >= 41) << endl;

    double hourlyRate = 25.00;
    cout << (hourlyRate < 25.00) << endl;
    cout << (hourlyRate <= 25.00) << endl;

    return (0);
};
