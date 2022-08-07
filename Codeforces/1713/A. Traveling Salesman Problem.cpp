#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, i, maxNegativeXAxis, maxNegativeYAxis, maxPositiveXAxis, maxPositiveYAxis, x, y;
    
    maxNegativeXAxis = maxNegativeYAxis = maxPositiveXAxis = maxPositiveYAxis = 0;

    cin >> n;
    for (i = 0; i < n; ++i) {
        cin >> x >> y;

        if (x == 0) {
            if (y > 0) {
                maxPositiveYAxis = max(maxPositiveYAxis, y);
            } else {
                maxNegativeYAxis = min(maxNegativeYAxis, y);
            }
        } else if (y == 0) {
            if (x > 0) {
                maxPositiveXAxis = max(maxPositiveXAxis, x);
            } else {
                maxNegativeXAxis = min(maxNegativeXAxis, x);
            }
        }
    }


    cout << (maxPositiveYAxis * 2) + (maxNegativeYAxis * -2) + (maxPositiveXAxis * 2) + (maxNegativeXAxis * -2) << endl;
}

int main() {

    // freopen("in.txt", "r", stdin);

    int test;
    cin >> test;
    while(test--) {
        solve();
    }

    return (0);
}