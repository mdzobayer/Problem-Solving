#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll gcdLoop(ll a, ll b) {
    while(b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

ll binaryGCD(ll a, ll b) {
    if (!a || !b) {
        return a | b;
    }

    unsigned shift = __builtin_ctz(a | b);
    a >>= __builtin_ctz(a);
    
    do {
        b >>= __builtin_ctz(b);
        if (a > b) {
            swap(a, b);
        }

        b -= a;
    } while(b);

    return (a << shift);
}

ll lcm(ll a, ll b) {
    return (a / binaryGCD(a, b) * b);
}

int main() {

    ll test, t, a, b, gcd, lcm;

    scanf("%lld", &test);
    for (t = 0; t < test; ++t) {
        scanf("%lld %lld", &a, &b);

        gcd = binaryGCD(a, b);

        printf("%lld %lld\n", gcd, (a / gcd) * b);
    }

    return (0);
}