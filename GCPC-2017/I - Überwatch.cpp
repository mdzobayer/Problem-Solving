#include <bits/stdc++.h>

using namespace std;

#define N 300000+5
#define M 10+5

int n, m, arr[N], dp[N][M];

int solve(int index, int power) {
    if (index >= n) return (0);

    if (dp[index][power] != -1) return dp[index][power];

    int ans = 0;
    if (power == m) {
        ans = max(ans, solve(index + 1, 1) + arr[index]);
    }
    ans = max(ans, solve(index + 1, min(power + 1, m)));

    return dp[index][power] = ans;
}

int main() {

    // freopen("in.txt", "r", stdin);

    int i;
    scanf("%d %d", &n, &m);
    for (i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    memset(dp, -1, sizeof(dp));
    printf("%d\n", solve(m, m));

    return (0);
}