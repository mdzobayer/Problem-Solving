#include <cstdio>
#include <cctype>
#include <iostream>
using namespace std;
string str;
string maxStr;

int main() {
    int len = 0;
    int Max = 0;
    while(cin >> str && str != "E-N-D") {
        len = str.length();
        if (len > Max) {
            maxStr = str;
            Max = maxStr.length();
        }
    }
    len = 0;
    while(maxStr[len]) {
        putchar(tolower(maxStr[len]));
        ++len;
    }
    putchar('\n');

    return (0);
}
