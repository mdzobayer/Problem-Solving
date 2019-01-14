#include <cstdio>
#include <cstring>
#include <iostream>
#include <sstream>
using namespace std;

string reverseString (const string & s) {
    int i, j;
    string temp = "";
    for ( i = s.length() - 1, j = 0; j < s.length(); --i, ++j) {
        temp += s[i];
    }
    return temp;
}

int main() {

    int g, len, k, j;
    string str;
    while(scanf("%d", &g)) {
        if (g == 0)
            break;
        k = 0;
        cin >> str;
        getchar();
        stringstream finalStr;
        len = str.length();
        len /= g;
        for ( j = 0; j <= str.length(); ) {
            stringstream ss;
            for ( k = j; k < (len + j); ++k) {
                ss << str[k];
            }
            j = k;
            if ( j <= str.length()) {
                finalStr << reverseString(ss.str());
            }
        }
        cout << finalStr.str() << endl;

    }

    return (0);
}
