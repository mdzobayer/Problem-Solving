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

    return d;
}

tuple<ll, ll, ll> gcdWithTuple(ll a, ll b) {
    if (b == 0) {
        return {1, 0, a};
    }

    ll x, y, g;

    tie(x, y, g) = gcdWithTuple(b, a % b);

    return {y, x - y * (a / b), g};
}

int main() {

    ll a = 55, b = 80, x, y, g;

    g = gcdExtended(a, b, x, y);
    printf("%lld %lld %lld\n", x, y, g);

    tie(x, y, g) = gcdWithTuple(a, b);
    printf("%lld %lld %lld\n", x, y, g);

    return (0);
}