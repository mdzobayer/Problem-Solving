#include <bits/stdc++.h>

using namespace std;

int main() {

    int i, sum, digit;
    string s, result = "";
    cin >> s;
    for (i = 0; i < s.size(); ++i) {
        digit = (s[i] - '0');
        if ((9 - digit) < digit) {
            if (i == 0 && (9 - digit) == 0) {
                result += s[i];
            } else result += to_string((9 - digit));
        } else {
            result += s[i];
        }
    }
    cout << result << endl;

    return (0);
}