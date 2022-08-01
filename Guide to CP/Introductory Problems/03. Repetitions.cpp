#include <bits/stdc++.h>

using namespace std;

int main() {

    string s;
    int len, i, maxLen = 0, currentLen;

    cin >> s;
    len = s.size();
    currentLen = 1;
    for (i = 1; i < len; ++i) {
        if (s[i] == s[i - 1]) {
            ++currentLen;
        }
        else {
            maxLen = max(maxLen, currentLen);
            currentLen = 1;
        }
    }
    maxLen = max(maxLen, currentLen);

    cout << maxLen << endl;

    return (0);
}