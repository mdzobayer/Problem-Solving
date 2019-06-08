#include <bits/stdc++.h>

using namespace std;
#define SIZE 100000+5
#define ll long long int

int n, m, arr[SIZE];
ll dp[SIZE];

ll solve() {

    int i;
    arr[0] = 0;
    for (i = 1; i <= n; ++i) {
        scanf("%d", &arr[i]);
        arr[i] = (arr[i] + arr[i - 1]) % m;
    }

    ll cnt = 0;
    memset(dp, 0, sizeof(dp));

    for (i = 1; i <= n; ++i) {
        cnt += dp[arr[i]];
        ++dp[arr[i]];
        if (arr[i] == 0) ++cnt;
    }

    return cnt;
}

int main() {

    int test, t;
    scanf("%d", &test);

    for (t = 1; t <= test; ++t) {
        scanf("%d %d", &n, &m);
        printf("Case %d: %lld\n", t, solve());
    }

    return (0);
}