#include <iostream>
using namespace std;
/*
void swapPointer(int *num1, int *num2){
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}
*/
void swapRef(int &num1, int &num2){
    int temp = num1;
    num1 = num2;
    num2 = temp;
}
int main(){
    int number1, number2;
    number1 = 13;
    number2 = 12;
    cout << "Number1: " << number1 << endl;
    cout << "Number2: " << number2 << endl;
    swapRef(number1,number2);
    cout << "Number1: " << number1 << endl;
    cout << "Number2: " << number2 << endl;
    return (0);

};
