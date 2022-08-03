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

bool find_any_solution(ll a, ll b, ll c, ll & x0, ll & y0, ll & g) {
    g = gcdExtended(abs(a), abs(b), x0, y0);

    if (c % g) {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;

    return true;
}

int main() {

    ll result, test, t, a, b, c, p, x, y, gcd;

    scanf("%lld", &test);
    for (t = 0; t < test; ++t) {
        scanf("%lld %lld %lld %lld", &a, &b, &c, &p);

        result = 0;

        find_any_solution(a, b, p, x, y, gcd);
        printf("x = %lld y = %lld gcd = %lld\n", x, y, gcd);
        if (x >= 0 && y >= 0 && p % gcd == 0) {
            ++result;
        }

        find_any_solution(a, c, p, x, y, gcd);
        printf("x = %lld y = %lld gcd = %lld\n", x, y, gcd);
        if (x >= 0 && y >= 0 && p % gcd == 0) {
            ++result;
        }

        find_any_solution(b, c, p, x, y, gcd);
        printf("x = %lld y = %lld gcd = %lld\n", x, y, gcd);
        if (x >= 0 && y >= 0 && p % gcd == 0) {
            ++result;
        }

        printf("Case %lld: %lld\n", t + 1, result);
    }

    return (0);
}