#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll countOrdinaryNumbers(ll base, ll maxRange) {
    ll count = 0, ordinary;
    ordinary = base;

    while(ordinary <= maxRange) {
        ++count;
        ordinary *= 10;
        ordinary += base;
    }

    return count;
}

int main() {

    // freopen("in.txt", "r", stdin);

    ll test, n, i, ans;
    cin >> test;

    while(test--) {
        cin >> n;
        ans = 0;
        for (i = 1; i <= 9; ++i) {
            ans += countOrdinaryNumbers(i, n);
        }
        cout << ans << endl;
    }

    return (0);
}