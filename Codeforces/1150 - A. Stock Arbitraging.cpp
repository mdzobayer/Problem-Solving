#include <bits/stdc++.h>

using namespace std;

int s[40], b[40], have[40];

vector < pair < int , int > > vt;

int main() {

    int n, m, r, i, mx = 0, sn = INT_MAX, bm = 0, noSell;
    cin >> n >> m >> r;
    noSell = r;
    for (i = 1; i <= n; ++i) {
        cin >> s[i];
        sn = min(sn, s[i]);
    }
    for (i = 1; i <= m; ++i) {
        cin >> b[i];
        bm = max(bm, b[i]);
    }

    sort(vt.begin(), vt.end());

    //cout << "Debug 1" << endl;
    if (r >= sn) {
        int x = r / sn;
        r -= (sn * x);
        mx += (x * bm);
    }


    mx += r;
    cout << max(mx, noSell) << endl;


    return (0);
}