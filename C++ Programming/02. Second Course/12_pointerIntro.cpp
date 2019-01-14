#include <iostream>

using namespace std;

void swap(int &number1, int &number2){
    int temp = number1;
    number1 = number2;
    number2 = temp;
}
int main(){
    /*
    int num1, num2;
    cout << "Enter two integer number: ";
    cin >> num1 >> num2;
    swap(num1, num2);
    cout << "number 1: " << num1 << endl;
    cout << "number 2: " << num2 << endl;
    */

    int number = 1;
    int *ptrNumber = &number;
    cout << ptrNumber << endl;
    cout << *ptrNumber << endl;
    string name = "Zobayer";
    string *ptrName;
    ptrName = &name;
    cout << ptrName << endl;
    cout << *ptrName << endl;

    return (0);
}
