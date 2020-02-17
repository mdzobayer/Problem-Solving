#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll calc (ll i, ll j) {
    if (j <= -1 || j > i) return 0;
    else if (i == 0 && j == 0) return 1;

    return calc(i - 1, j - 1) + calc(i - 1, j);
}

int main() {

    freopen("out.txt", "w", stdout);

    ll n, i, m = 0;
    for (n = 0; n <= 100; ++n) {
        for (i = 0; i <= n; ++i) {
            if (calc(n, i) % 2 == 0) {
                ++m;
            }
        }
        cout << n << " " << m << endl;
    }
    return (0);
}