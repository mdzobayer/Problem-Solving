#include <bits/stdc++.h>


using namespace std;

int main() {

    string str;
    int a, i, b, c;
    a = b = c = 0;
    cin >> str;

    for (i = 0; i < str.size(); ++i) {
        if (str[i] == 'a') {
            if (b > 0 || c > 0) {
                cout << "NO" << endl;
                return (0);
            }
            ++a;
        }
        else if (str[i] == 'b') {
            if (a < 1 || c > 0) {
                cout << "NO" << endl;
                return (0);
            }
            ++b;
        }
        else {
            if (a < 1 || b < 1) {
                cout << "NO" << endl;
                return (0);
            }
            ++c;
        }
    }
    if (c == a || c == b && a > 0 && b > 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return (0);
}
