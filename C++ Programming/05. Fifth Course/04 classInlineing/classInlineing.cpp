#include <iostream>
using namespace std;

#define Add2(x,y) x + y // C Preprocessor macro should not be used!

int inline Add2Int(int n1, int n2)
{
    return n1 + n2;
}

int main() {

    int num1 = 100;
    int num2 = 200;
    double num3 = 333.33;
    double num4 = 111.11;

    // The following 3 lines use the Add2 #defined macro expanded inline
    cout << Add2(10, 20) << endl;
    cout << Add2(num1, num2) << endl;
    cout << Add2(num3, num4) << endl;

    // The following 3 lines cause Add2Int to be expanded in place like a macro
    cout << Add2Int(10, 20) << endl;
    cout << Add2Int(30, 40) << endl;
    cout << Add2Int(num4, num3) << endl;

    return (0);
}
