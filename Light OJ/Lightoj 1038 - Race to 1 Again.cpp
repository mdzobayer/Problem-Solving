#include <bits/stdc++.h>


using namespace std;


#define MAX 100005

double dp[MAX];

int main() {
    int i, j, range, test, t, n;
    double sum, divisor;
    memset(dp, 0.0, sizeof(dp));

    for (i = 2; i < MAX; ++i) {
        divisor = -1;
        sum = 0.0;
        range = sqrt(i);
        for (j = 1; j <= range; ++j) {
            if (i % j == 0) {
                sum += ( 1 + dp[j]);
                ++divisor;
                if (i / j != j) {
                    sum += (1 + dp[i / j]);
                    ++divisor;
                }
            }

        }
        dp[i] = sum / divisor;
    }

    scanf("%d", &test);
    for (t = 1; t <= test; ++t) {
        scanf("%d", &n);
        printf("Case %d: %f\n", t, dp[n]);
    }

    return (0);
}
