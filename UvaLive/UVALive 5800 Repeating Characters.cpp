#include <bits/stdc++.h>

using namespace std;

int main() {

    int i, t, u, test, n, r, j;
    string s;
    cin >> test;
    for (t = 1; t <= test; ++t) {
        cin >> n >> r >> s;
        string tmp;
        for (i = 0; i < s.size(); ++i) {
            for (j = 0; j < r; ++j) {
                tmp += s[i];
            }
        }
        cout << n << " " << tmp << endl;
    }

    return (0);
}
