#include <bits/stdc++.h>

using namespace std;

int timeCost[2][1000+5], jump[2][1000+5], n, dp[3][1000+5];

int solve(int building, int floor) {
    if (floor >= n) return (0);

    if (dp[building][floor] != -1) return dp[building][floor];

    int ans = INT_MAX, nextBuilding;

    if (building == 0) nextBuilding = 1;
    else nextBuilding = 0;

    ans = min(ans, timeCost[building][floor] + solve(building, floor + 1));
    ans = min(ans, jump[building][floor] + timeCost[building][floor] + solve(nextBuilding, floor + 1));

    return dp[building][floor] = ans;
}

int main() {

    //freopen("in.txt", "r", stdin);

    int test, t, i, ans;
    scanf("%d", &test);
    for (t = 1; t <= test; ++t) {
        scanf("%d", &n);
        for (i = 0; i < n; ++i) {
            scanf("%d", &timeCost[0][i]);
        }
        for (i = 0; i < n; ++i) {
            scanf("%d", &timeCost[1][i]);
        }

        for (i = 0; i < n - 1; ++i) {
            scanf("%d", &jump[0][i]);
        }
        for (i = 0; i < n - 1; ++i) {
            scanf("%d", &jump[1][i]);
        }

        memset(dp, -1, sizeof(dp));

        ans = solve(0, 0);
        ans = min(ans, solve(1, 0));
        printf("Case %d: %d\n", t, ans);
    }

    return (0);
}