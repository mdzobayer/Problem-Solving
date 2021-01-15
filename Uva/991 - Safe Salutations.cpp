#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll dp[] = {1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862};

ll catalan(ll n) {
    if (n < 1)
    return 1;

    if (dp[n] != -1)
        return dp[n];
    
    dp[n] = 0;
    for (ll i = 0; i < n; ++i) {
        dp[n] += (catalan(i) * catalan(n-i-1));
    }

    return dp[n];
}


int main() {

    // memset(dp, -1, sizeof(dp));
    // for (ll i = 0; i < 11; ++i) {
    //     catalan(i);
    // }

    ll n;
    bool isFirst = true;
    
    while (scanf("%lld", &n) == 1)
    {
        if (!isFirst) {
            puts("");
        }
        printf("%lld\n", dp[n]);
        isFirst = false;
    }
    
    return (0);
}