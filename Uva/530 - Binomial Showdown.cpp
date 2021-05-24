#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main () {

    ll n, k, result, i, j, maxDenominator, minDenominator;

    while(scanf("%lld %lld", &n, &k) == 2) {
        if (n == 0 && k == 0) break;

        maxDenominator = max((n-k), k) + 1;
        minDenominator = min((n-k), k);

        // printf("max = %lld min = %lld\n", maxDenominator, minDenominator);

        result = 1;
        j = 1;

        for (i = maxDenominator; i <= n; ++i) {
            for ( ; j <= minDenominator; ++j) {
                if (result % j == 0) {
                    result /= j;
                }
                else break;
            }

            result *= i;
        }

        for (; j <= minDenominator; ++j) {
            result /= j;
        }

        printf("%lld\n", result);
    }

    return (0);
}
