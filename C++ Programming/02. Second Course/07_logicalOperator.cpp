#include <iostream>
using namespace std;
int main(){

    int hoursWorked = 40;
    double hourlyRate = 9.75;
    cout << ((hoursWorked < 1) || (hoursWorked > 56)) << endl;

    cout << ((hoursWorked <= 40) && (hourlyRate <= 10.00)) << endl;

    cout << !(hoursWorked == 40) << endl;
    return (0);
};
