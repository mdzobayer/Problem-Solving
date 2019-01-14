#include <bits/stdc++.h>
#define SIZE 20
using namespace std;

int arr[SIZE][SIZE], dp[65540][SIZE], target, n;

int solve(int mask, int p) {
    if (mask == target || p >= n)
        return (0);

    if (dp[mask][p] != -1) return dp[mask][p];

    int & ans = dp[mask][p]; int i;

    ans = 0;
    for (i = 0; i < n; ++i) {
        if ((mask & (1 << i)) == 0) {
            ans = max(ans, solve((mask | (1 << i)), p+1) + arr[p][i]);
        }
    }
    return ans;
}

int main() {

    //freopen("in.txt", "r", stdin);

    int test, t, i, j;
    scanf("%d", &test);
    for (t = 1; t <= test; ++t) {
        scanf("%d", &n);

        target = (1 << n) - 1;

        for (i = 0; i < n; ++i) {
            for (j = 0; j < n; ++j) {
                scanf("%d", &arr[i][j]);
            }
        }
        memset(dp, -1, sizeof(dp));
        printf("Case %d: %d\n", t, solve(0, 0));

    }

    return (0);
}
