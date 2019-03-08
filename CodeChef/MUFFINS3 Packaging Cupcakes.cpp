#include <bits/stdc++.h>

using namespace std;

int main() {

    int t, n, test, x;
    cin >> test;
    for (t = 0; t < test; ++t) {
        cin >> n;
        if (n == 2) {
            cout << "2" << endl;
        }
        else {
            x = n / 2;
            ++x;
            cout << x << endl;
        }
    }

    return (0);
}