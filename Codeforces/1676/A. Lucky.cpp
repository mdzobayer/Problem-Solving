#include <bits/stdc++.h>

using namespace std;

int main() {

    int test, i, x, y;
    string s;
    cin >> test;
    while(test--) {
        cin >> s;

        x = ((s[0] + s[1] + s[2]) - (int)('0' * 3));
        y = ((s[3] + s[4] + s[5]) - (int)('0' * 3));
        if (x == y) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return (0);
}