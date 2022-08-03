#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main() {

    char data[5];
    string s;

    ll result;
    int i, g = 34943;

    while(getline(cin, s)) {
        if (s == "#") break;

        if (s.size() == 0) {
            puts("00 00");
            continue;
        }

        result = s[0];
        for (i = 0; i < s.size(); ++i) {
            result %= g;
            result <<= 8;
            result += s[i];
        }

        result <<= 16;
        result = g - (result % g);

        sprintf(data, "%04X", result);

        printf("%c%c %c%c\n", data[0], data[1], data[2], data[3]);
    }

    return (0);
}