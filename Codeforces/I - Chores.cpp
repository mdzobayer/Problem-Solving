#include <bits/stdc++.h>


using namespace std;
vector < int > vt;
int main() {

    int n, k, x, i, tmp, r;

    cin >> n >> k >> x;
    for (i = 0; i < n; ++i) {
        cin >> tmp;
        vt.push_back(tmp);
    }
    sort(vt.begin(), vt.end());
    r = n - k;
    tmp = 0;
    for (i = 0; i < r; ++i) {
        tmp += vt[i];
    }
    tmp += (k * x);
    cout << tmp << endl;

    return (0);
}
