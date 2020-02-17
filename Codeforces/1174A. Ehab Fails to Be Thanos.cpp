#include <bits/stdc++.h>

using namespace std;

int main() {

    vector < int > vt;
    int n, x, i, n2x, sum = 0, tmp = 0;
    cin >> n;
    n2x = n * 2;

    for (i = 0; i < n2x; ++i) {
        cin >> x;
        sum += x;
        vt.push_back(x);
    }
    sort(vt.begin(), vt.end());
    for (i = 0; i < n; ++i) {
        tmp += vt[i];
    }
    if (tmp * 2 == sum) {
        cout << "-1" << endl;
    }
    else {
        for (i = 0; i < n2x; ++i) {
            cout << vt[i] << " ";
        }
        cout << endl;
    }


    return (0);
}