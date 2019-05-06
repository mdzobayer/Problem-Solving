#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, m, j, h, i, l, r, x, arr[55];

    cin >> n >> h >> m;

    for (i = 1; i <= n; ++i) {
        arr[i] = h;
    }

    for (i = 0; i < m; ++i) {
        cin >> l >> r >> x;
        for (j = l; j <= r; j++) {
            arr[j] = min(arr[j], x);
        }
    }
    x = 0;
    for (i = 1; i <= n; ++i) {
        x += (arr[i] * arr[i]);
    }
    cout << x << endl;

    return (0);
}