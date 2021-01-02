#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll modpow(ll x, ll n, ll m) {
    if (n == 0) return 1 % m;

    ll u = modpow(x, n / 2, m);

    u = (u * u) % m;

    if (n & 1) {
        u = (u * x) % m;
    }

    return u;
}

int main() {

    int test, t;
    ll b, p, lead, tail;

    scanf("%d", &test);
    for (t = 0; t < test; ++t) {
        scanf("%lld %lld", &b, &p);

        lead = (ll) pow(10, 2+fmod(p * log10(b), 1));

        tail = modpow(b, p, 1000);

        printf("%lld...%03lld\n", lead, tail);
    }

    return (0);
}