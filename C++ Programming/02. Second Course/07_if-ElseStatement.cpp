#include <iostream>
using namespace std;
int main(){
    int hoursWorked;
    double rate, grossPay;
    cout << "Enter the hours worked: ";
    cin >> hoursWorked;
    cout << "Enter the rate of pay: ";
    cin >> rate;
    if (hoursWorked <= 40){
        grossPay = hoursWorked * rate;
    }
    else{
        grossPay = (40 * rate) + ((hoursWorked - 40) * (rate * 1.5));
    };
    cout << "Gross pay is: " << grossPay << endl;
    return (0);
};

