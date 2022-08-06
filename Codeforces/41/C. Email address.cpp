#include <bits/stdc++.h>

using namespace std;

int main() {

    string s, newStr = "";
    bool isAtSignFulFill;
    int i;
    cin >> s;

    for (i = 0; i < s.size() - 2; ++i) {
        if (s[i] == 'd' && s[i + 1] == 'o' && s[i + 2] == 't') {

            newStr += '.';
            i += 2;
        } else {
            newStr += s[i];
        }
    }

    newStr += s.substr(i);
    s = newStr;
    newStr = "";
    isAtSignFulFill = false;

    for (i = 0; i < s.size() - 1; ++i) {
        if (s[i] == 'a' && s[i + 1] == 't' && i > 0 && !isAtSignFulFill) {
            newStr += '@';
            isAtSignFulFill = true;
            i += 1;
        } else {
            newStr += s[i];
        }
    }

    newStr += s.substr(i);

    if (newStr[0] == '.') {
        newStr = "dot" + newStr.substr(1);
    }

    if (newStr.back() == '.') {
        newStr = newStr.substr(0, newStr.size() - 1) + "dot";
    }
    cout << newStr << endl;

    return (0);
}