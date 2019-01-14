#include <bits/stdc++.h>

using namespace std;

int main() {

    int i, sz, rs, rm, astrick;

    string s;
    cin >> s;
    sz = s.size();

    cout << sz << endl;

    rs = sz / 20;
    rm = sz % 20;

    if(rs == 0 || (rs == 1 && rm == 0)) {
        cout << 1 << " " << s.size() << endl;
        cout << s << endl;
    }
    else {
        if(rm > 0) {
            ++rs;
        }
        astrick = 20 - rm;

    }

    return (0);
}
