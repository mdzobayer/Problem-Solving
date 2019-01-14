/*an exception handling allows to keep our program
from crashing back to operating system. An other
words it allows to needly handle errors in our
programs also called exceptions. So that our program
don't crash*/

#include <iostream>

using namespace std;
const int DivideByZero = 1;
int main() {
    /*
    int numer = 12;
    int denom = 0;
    cout << numer / denom;
    */
    try {
        int numer = 12;
        int denom = 0;
        if (denom == 0) {
            throw DivideByZero;
        }
        else {
            cout << numer / denom;
        }
    }
    catch(int e) {
        if (e == DivideByZero) {
            cout << "Can't divide by zero." << endl;
        }
    }
    return (0);
};
