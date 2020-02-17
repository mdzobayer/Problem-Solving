#include <bits/stdc++.h>

using namespace std;

int main() {

    //freopen("in.txt", "r", stdin);

    long long int a, b, c, test;
    cin >> test;
    while(test--) {
        cin >> a >> b >> c;

        if (a == 0 || b == 0 || c == 0) {
            cout << "NO" << endl;
        }
        else if ((a + b + c) != 180) {
            cout << "NO" << endl;
        }
        else {
            cout << "YES" << endl;
        }
    }

    return (0);
}