/* stringize(#) and pasting(##) operator */
#include <iostream>

#define makeString(str) # str
#define concatenate(a, b) a ## b
using namespace std;

int main() {
    // Stringize Operator (#)
    cout << makeString(Hello Bangladesh!) << endl;
    int xy = 25;
    cout << concatenate(x,y) << endl;

    char ch[9];
    cout << ch << endl;

    return (0);
};
