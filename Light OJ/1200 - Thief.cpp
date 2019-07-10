#include <bits/stdc++.h>

using namespace std;


int N, W, price[105], weight[105], dp[105][10000+5];

int solve(int position, int avilableWeight) {
    if (position < 0 || avilableWeight <= 0) {
        return (0);
    }

    if (dp[position][avilableWeight] != -1) {
        return dp[position][avilableWeight];
    }

    int ans = 0;

    if (avilableWeight >= weight[position]) {
        ans = max(ans, price[position] + solve(position, avilableWeight - weight[position]));
    }
    ans = max(ans, solve(position - 1, avilableWeight));

    return dp[position][avilableWeight] = ans;
}

int main() {

    //freopen("in.txt", "r", stdin);

    int test, t, i, quantity, essential;
    scanf("%d", &test);
    for (t = 1; t <= test; ++t) {
        scanf("%d %d", &N, &W);

        essential = 0;

        for (i = 0; i < N; ++i) {
            scanf("%d %d %d", &price[i], &quantity, &weight[i]);
            essential += weight[i] * quantity;
        }

        printf("Case %d: ", t);
        if (essential > W) {
            printf("Impossible\n");
        }
        else {
            //w -= essential;

            memset(dp, -1, sizeof(dp));

            printf("%d\n", solve(N - 1, W - essential));
        }
    }

    return (0);
}