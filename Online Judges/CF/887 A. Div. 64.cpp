#include <bits/stdc++.h>

using namespace std;

int main () {
    int a = 0, b, c, zeros = 0, ones = 0;
    bool isPossible = false;
    string s;

    cin >> s;
    b = s.size();
    if (b < 6) {
        cout << "no" << endl;
        return (0);
    }

    for (--b; b >= 0; --b) {
        if (s[b] == '0') {
            ++zeros;
        }
        if (zeros == 6) {
            --b;
            break;
        }
    }
    if (zeros == 6 && b >= 0) {
            for (b; b >= 0; --b) {
                if (s[b] == '1') {
                    cout << "yes" << endl;
                    return (0);
                }
            }
        }
        cout << "no" << endl;

    return (0);
}
