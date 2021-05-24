#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll dp[500];

ll catalan (ll n) {

    if (n < 1) {
        return 1;
    }

    if (dp[n] != -1) {
        return dp[n];
    }

    ll res = 0;

    for (int i = 0; i < n; ++i) {
        res += catalan(i) * catalan(n - i - 1);
    }

    return dp[n] = res;
}

int main() {

    memset(dp, -1, sizeof(dp));
    
    for (int i = 0; i < 10; ++i) {
        cout << catalan (i) << " ";
    }

    puts("");

    return (0);
}