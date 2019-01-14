#include <cstdio>
#include <climits>
#include <cstring>

int min(int x, int y) {
    return x < y ? x : y;
}
int dp[100+5][100+5];

int solve(int arr[], int s, int e) {
    //printf("start : %d end %d\n", s, e);
    if (dp[s][e] != -1) {
        return dp[s][e];
    }
    if (s == e) {
        return dp[s][e] = 1;
    }
    if (s > e) {
        return dp[s][e] = 0;
    }

    dp[s][e] = 1 + solve(arr, s+1, e);

    for (int i = s + 1; i <= e; ++i) {
        if (arr[s] == arr[i]) {
            dp[s][e] = min (dp[s][e], (solve(arr, s+1, i) + solve(arr, i+1, e)));
        }
    }
    return dp[s][e];
}

int main() {

    int test, t, n, i, arr[105];
    scanf("%d", &test);
    for (t = 1; t <= test; ++t) {
        scanf("%d", &n);
        for (i = 1; i <= n; ++i) {
            scanf("%d", &arr[i]);
        }
        memset(dp, -1, sizeof(dp));
        printf("Case %d: %d\n", t, solve(arr, 1, n));
    }

    return (0);
}
