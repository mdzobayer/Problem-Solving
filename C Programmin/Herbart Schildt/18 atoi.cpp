#include <iostream>
//#include <cstdlib>
//#include <cstdio>

using namespace std;

int main() {

    char num1[10] = "10.25";
    char num2[10] = "85";

    cout << atoi(num1) + atoi(num2) << endl;
    char s[80];
    int c;

    do {
        cout << "Enter your choice: ";
        gets(s);
        c = atoi(s);
        cout << c << endl;
    }while(c < 1 || c > 4);

    cout << c << endl;

    return (0);
}
