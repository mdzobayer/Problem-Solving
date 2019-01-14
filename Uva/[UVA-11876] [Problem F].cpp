#include <cstdio>
#include <cmath>

int index[1000001], dp[100001];

int divisor(int x) {
    int i, j, count = 0;
    for (i = 1; i <= sqrt(x); ++i) {
        if (x % i == 0) {
            count++;
            if (x / i != i) count++;
        }
    }
    return count;
}

int main() {

    dp[1] = 1;
    index[1] = 1;
    int i, j, n, a, b;
    for (i = 2; i < 1000000; ++i) {
        dp[i] = dp[i - 1] + divisor(dp[i - 1]);
        if (dp[i] > 1000000) {
            for (j = dp[i - 1] + 1; j <= 1000000; ++j) {
                index[j] = i - 1;
            }
            break;
        }
        for (j = dp[i - 1] + 1; j < dp[i]; ++j) {
            index[j] = i - 1;
        }
        index[dp[i]] = i;
    }

    scanf("%d", &n);
    for (i = 1; i <= n; ++i) {
        scanf("%d %d", &a, &b);
        printf("Case %d: %d\n", i, index[b] - index[a - 1]);
    }

    return (0);
}
