#include <iostream>
using namespace std;
int main(){

    int number, factorial;
    cout << "Enter a number for factorial: ";
    cin >> number;
    factorial = 1;
    cout << number << "! = ";
    for(int i = number; i >=1; --i){
        if((number != i) && (i != 0)){
            cout << " * ";
        }
        factorial *= i;
        cout << i;
    }
    cout << " = " << factorial << endl;
    cout << number << "! equal " << factorial << endl << endl;


    int data1, data2, data3;
    cout << endl << "Enter the three number: ";
    cin >> data1 >> data2 >> data3;
    for(int i = 1; i <= data1; ++i){
        cout << "*";
    };
    cout << " " << data1 << endl;

    for(int i = 1; i <= data2; ++i){
        cout << "*";
    };
    cout << " " << data2 << endl;

    for(int i = 1; i <= data3; ++i){
        cout << "*";
    };
    cout << " " << data3 << endl;

    return (0);

};
