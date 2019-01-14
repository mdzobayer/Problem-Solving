#include <iostream>

using namespace std;

int main(){
    int number1, number2, result1;
    number1 = 22;
    number2 = 2;
    result1 = number1 + number2 * 10;
    result1 = 12 / 2 * 3 + 6 - 1;
    cout << result1 << endl;
    result1 = 12 / 2 * ((3 + 6) - 1);
    cout << result1 << endl;

    int grade1, grade2, grade3;
    double average;
    grade1 = 74;
    grade2 = 82;
    grade3 = 88;
    average = (float)(grade1 + grade2 + grade3 )/ 3;
    cout << average << endl;
    return (0);
}
