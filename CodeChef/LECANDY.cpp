#include <bits/stdc++.h>

using namespace std;

int main() {

    int test, n, c, i, x;
    cin >> test;
    while(test--) {
        cin >> n >> c;
        for (i = 0; i < n; ++i) {
            cin >> x;
            c -= x;
        }

        if (c < 0) {
            cout << "No" << endl;
        }
        else {
            cout << "Yes" << endl;
        }
    }

    return (0);
}