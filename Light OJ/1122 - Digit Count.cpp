#include <bits/stdc++.h>
#define ll long long int
#define SIZE 15
using namespace std;

int n, m, arr[SIZE];

ll dp[SIZE][SIZE];

ll solve(int pos, int remain) {
    if (pos >= m || pos < 0) return (0);

    //printf("Called pos %d remain %d\n", pos, remain);

    if (remain == 1) return 1;

    if (dp[pos][remain] != -1) return dp[pos][remain];

    ll ans = 0;
    ans += solve(pos, remain - 1);  // Same Character again

    if (pos + 1 >= 0 && pos + 1 < m)
        if (abs(arr[pos + 1] - arr[pos]) < 3)
            ans += solve(pos + 1, remain - 1); // Post character 

    if (pos + 2 >= 0 && pos + 2 < m)
        if (abs(arr[pos + 2] - arr[pos]) < 3)
            ans += solve(pos + 2, remain - 1); // 2nd Post character 

    if (pos - 1 >= 0 && pos - 1 < m)
        if (abs(arr[pos] - arr[pos - 1]) < 3)
            ans += solve(pos - 1, remain - 1); // Previous character again
    
    if (pos - 2 >= 0 && pos - 2 < m)
        if (abs(arr[pos] - arr[pos - 2]) < 3)
            ans += solve(pos - 2, remain - 1); // 2nd Previous character again

    return dp[pos][remain] = ans;
}

int main() {

    int test, t, i;
    scanf("%d", &test);
    for (t = 1; t <= test; ++t) {
        scanf("%d %d", &m, &n);

        for (i = 0; i < m; ++i) {
            scanf("%d", &arr[i]);
        }

        memset(dp, -1, sizeof(dp));
        ll ans = 0;
        for (i = 0; i < m; ++i) {
            ans += solve(i, n);
        }
        printf("Case %d: %lld\n", t, ans);
    }

    return (0);
}
/*
11
12
13
*/