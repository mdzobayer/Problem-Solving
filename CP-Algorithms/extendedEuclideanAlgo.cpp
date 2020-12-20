#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll gcdExtended(ll a, ll b, ll & x, ll & y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    ll x1, y1;

    ll d = gcdExtended(b, a % b, x1, y1);

    x = y1;
    y = x1 - y1 * (a / b);

    printf("x = %lld y = %lld (a/b) = %lld\n", x, y, (a/b));

    return d;
}

int main() {

    ll a = 55, b = 80, x, y;

    printf("%lld\n", gcdExtended(a, b, x, y));
    printf("%lld %lld", x, y);

    return (0);
}