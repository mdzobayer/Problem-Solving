#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll binaryPowerModule(ll base, ll power, ll module) {
    ll result = 1;
    base %= module;

    while (power > 0) {
        if (power & 1) {
            result = (result * base) % module;
        }

        base = (base * base) % module;
        power >>= 1;
    }

    return result;
}

int main() {
    // freopen("in.txt", "r", stdin);

    ll test, base, power, module;

    scanf("%lld", &test);
    while(test > 0) {
        --test;

        scanf("%lld %lld %lld", &base, &power, &module);

        printf("%lld\n", binaryPowerModule(base, power, module));
    }

    return (0);
}
