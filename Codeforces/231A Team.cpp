#include <bits/stdc++.h>

using namespace std;

int main() {


    int n, i, im = 0, a, b, c, pos;
    cin >> n;
    for (i = 0; i < n; ++i) {
        pos = 0;
        cin >> a >> b >> c;
        if (a) ++pos;
        if (b) ++pos;
        if (c) ++pos;
        if (pos > 1) ++im;
    }
    cout << im << endl;


    return (0);
}