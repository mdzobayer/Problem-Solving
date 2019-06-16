#include <bits/stdc++.h>

using namespace std;

int main() {

    freopen("leapfrog_ch_.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    string s;
    int t, test, len, Bs, empty, i;
    cin >> test;
    cin.ignore();
    for (t = 1; t <= test; ++t) {

        Bs = empty = 0;

        cin >> s;
        len = s.size();

        for (i = 1; i < len; ++i) {
            if (s[i] == '.') {
                ++empty;
            }
            else if (s[i] == 'B') {
                ++Bs;
            }
        }

        if (empty == 0 || Bs == 0) {
            cout << "Case #"<< t << ": N" << endl;
        }
        else if (Bs > 2) {
            cout << "Case #"<< t << ": Y" << endl;
        }
        else if (Bs >= empty) {
            cout << "Case #"<< t << ": Y" << endl;
        }
        else {
            cout << "Case #"<< t << ": N" << endl;
        }
    }

    return (0);
}