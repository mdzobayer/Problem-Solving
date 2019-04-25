#include <bits/stdc++.h>

using namespace std;

int main() {

    int x, xi, n, i;
    string s;

    cin >> n >> s;

    xi = 0;

    for (i = 1; i < n; ++i) {
        if (s[i] < s[xi]) {
            cout << "YES" << endl << xi + 1 << " " << i + 1 << endl;
            return (0);
        }
        else if (s[i] > s[xi]) {
            xi = i;
        }
    }

    cout << "NO" << endl;


    return (0);
}