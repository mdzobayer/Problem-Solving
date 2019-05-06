#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, m, i, j, x;
    map < int, int > mp;

    scanf("%d %d", &n, &m);

    for (i = 0; i < n; ++i) {
        for (j = 0; j < m; ++j) {
            scanf("%d", &x);
            mp[x] += 1;
        }
    }

    for (i = 0; i < n; ++i) {
        for (j = 0; j < m; ++j) {
            scanf("%d", &x);
            mp[x] += 1;
        }
    }

    for (auto it = mp.begin(); it != mp.end(); ++it) {
        if (it->second > 2) {
            cout << "Impossible" << endl;
            return (0);
        }
    }
    cout << "Possible" << endl;

    return (0);
}