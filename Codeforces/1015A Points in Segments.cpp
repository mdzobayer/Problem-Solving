#include <bits/stdc++.h>

using namespace std;

int cnn[105];

int main() {

    int n, m, i, l, r, j, Counter = 0;
    cin >> n >> m;
    for (i = 0; i < n; ++i) {
        cin >> l >> r;
        for (j = l; j <= r; ++j) {
            cnn[j] += 1;
        }
    }
    bool flag;
    flag = true;
    for (i = 1; i <= m; ++i) {
        if (cnn[i] == 0) {
            ++Counter;
        }
    }
    
    cout << Counter << endl;
    for (i = 1; i <= m; ++i) {
        if (cnn[i] == 0) {
            cout << i << " ";
        }
    }
    cout << endl;

    return (0);
}