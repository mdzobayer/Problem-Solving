#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, i, totalMove, eights = 0;
    string s;

    cin >> n >> s;

    totalMove = n - 11;

    for (i = 0; i <= totalMove; ++i) {
        if (s[i] == '8') {
            ++eights;
        }
    }
    //cout << eights << " " << totalMove << endl;

    if (totalMove % 2 == 0) {
        if (eights > (totalMove / 2)) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    else {
        if (eights >= (totalMove / 2)) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }


    return (0);
}