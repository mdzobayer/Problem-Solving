#include <iostream>

using namespace std;

int main(){
    /*int number;
    cin >> number;
    cout << number;

    int number1, number2;
    cin >> number1 >> number2;
    cout << "Number 1: " <<number1 << endl <<"Number 2: " << number2 << endl;*/

    int number1, number2, result;
    cout << "Enter the first number: ";
    cin >> number1;
    cout << "Enter the second number: ";
    cin >> number2;
    result = number1 + number2;
    cout << number1 << " + " << number2 << " = " << result << endl;
    return (0);
};
