#include <bits/stdc++.h>


using namespace std;


int main() {

    //freopen("in.txt", "r", stdin);

    string s, ss;
    int m, i, l, r, k, j;

    cin >> s;
    cin >> m;
    //cout << s << endl;
    for (i = 0; i < m; ++i) {
        cin >> l >> r >> k;

        k %= (r - l + 1);
        rotate(s.begin() + l - 1, s.begin() + r - k, s.begin() + r);
    }
    cout << s << endl;


    return (0);
}
