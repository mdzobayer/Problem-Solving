#include <iostream>
using namespace std;
int main(){
    //const double pi = 3.14159265;
    //cout << pi * 3;
    cout << (float)3/2 << endl;
    cout << 3/2.0 << endl;

    int number;
    double rate;
    number = 2;
    rate = 1.0345;
    number = rate;
    cout << number << endl; //Narrowing conversion
    rate = 2; //Widening conversion
    //implicit conversion
    //explicit conversion - type cast
    number = (int)rate;
    cout << number << endl;
    rate = (double)number;
    cout << rate << endl;

    return (0);
};
