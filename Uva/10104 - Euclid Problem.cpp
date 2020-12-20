#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll extendedGCDRecursive(ll a, ll b, ll & x, ll & y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    ll x1, y1;
    ll d = extendedGCDRecursive(b, a % b, x1, y1);

    x = y1;
    y = x1 - y1 * (a / b);

    return d;
}

int main() {

    ll a, b, x, y, d;

    while(scanf("%lld %lld", &a, &b) == 2) {
        d = extendedGCDRecursive(a, b, x, y);

        printf("%lld %lld %lld\n", x, y, d);
    }

    return (0);
}