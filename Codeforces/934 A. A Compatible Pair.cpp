#include <bits/stdc++.h>
#define LLI long long int
#define ULL unsigned long long int

using namespace std;
LLI n, m, a[55], b[55], i ,j, r;

int main() {

    cin >> n >> m;
    for (i = 0; i < n; ++i) {
        cin >> a[i];
        b[i] = -2e18;
    }
    for (i = 0; i < m; ++i) {
        cin >> r;
        for (j = 0; j < n; ++j) {
            b[j] = max(b[j], r * a[j]);
        }
    }
    sort(b, b + n);
    cout << b[n - 2] << endl;


    return (0);
}
