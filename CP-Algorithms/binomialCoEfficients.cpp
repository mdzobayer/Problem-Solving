#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll dp[50][10];

ll binomialCoEfficients(ll n, ll k) {

    if (k > n) return 0;
    if (k == 0 || k == n) return 1;

    if (dp[n][k] != -1) {
        return dp[n][k];
    }

    return dp[n][k] = binomialCoEfficients(n - 1, k - 1) + binomialCoEfficients(n - 1, k);
}

int main () {

    memset(dp, -1, sizeof(dp));

    ll result = binomialCoEfficients(10, 3);

    printf("%lld\n", result);

    return (0);
}