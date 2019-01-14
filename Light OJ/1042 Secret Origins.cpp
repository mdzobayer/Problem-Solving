#include <bits/stdc++.h>
#define ll long long int

ll numberOfBits(ll n) {
    ll i, cnn = 0;

    for (i = 1; i <= n; i *= 2) {
        if (n & i)
            ++cnn;
    }
    return cnn;
}


int main() {

    ll test, t, i, n, res, missing;
    scanf("%lld", &test);
    for (t = 1; t <= test; ++t) {
        scanf("%lld", &n);

        res = 0;
        for (i = 1; i <= n; i *= 2) {
            if (n & i) {
                res = n + i;
                break;
            }
        }
        missing = numberOfBits(n) - numberOfBits(res);

        for (i = 0; i < missing; ++i) {
            res += (1ll << i);
        }
        printf("Case %lld: %lld\n", t, res);
    }

    return (0);
}
