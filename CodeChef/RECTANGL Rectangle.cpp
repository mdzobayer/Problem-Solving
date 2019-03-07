#include <bits/stdc++.h>

using namespace std;

int main() {

    int a, b, c, d, test;
    cin >> test;
    while(test--) {
        cin >> a >> b >> c >> d;

        if (a == b && c == d) {
            cout << "YES" << endl;
        }
        else if (a == c && b == d) {
            cout << "YES" << endl;
        }
        else if (a == d && c == b) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }

    return (0);
}
