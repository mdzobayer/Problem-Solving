#include <cstdio>
#include <climits>
#include <cstring>

int arr[107], test, t, n, dp[107][107];

int max (int x, int y) {
    return x > y ? x : y;
}

int easyGame(int left, int right) {
    if (left > right) {
        return 0;
    }
    if (dp[left][right] != INT_MAX)
        return dp[left][right];

    dp[left][right] = arr[right] - arr[left - 1];
    int i, j;
    for (i = left; i <= right; ++i) {
        dp[left][right] = max (dp[left][right], (arr[i] - arr[left - 1]) - easyGame(i + 1, right));
        dp[left][right] = max (dp[left][right], (arr[right] - arr[i - 1]) - easyGame(left, i - 1));
    }

    return dp[left][right];
}

int main() {

    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int i, j;
    scanf("%d", &test);
    for (t = 1; t <= test; ++t) {
        scanf("%d", &n);
        for (i = 1; i <= n; ++i) {
            for (j = 1; j <= n; ++j) {
                dp[i][j] = INT_MAX;
            }
        }
        arr[0] = 0;
        for (i = 1; i <= n; ++i) {
            scanf("%d", &arr[i]);
            arr[i] += arr[i - 1];
        }
        printf("Case %d: %d\n", t, easyGame(1, n));
    }

    return (0);
}
