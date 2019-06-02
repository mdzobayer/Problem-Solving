#include <bits/stdc++.h>

using namespace std;
#define SIZE 20

int test, t, n, cost[SIZE][SIZE], target;

long long int bitmask[(1 << 14) + 5];

int solve (int mask, int cst) {
    if (mask == target) return cst;

    int i, j, tmpCost, ans = INT_MAX;

    for (i = 0; i < n; ++i) {
        if ((mask & (1 << i)) == 0) {
            tmpCost = cost[i][i];
            for (j = 0; j < n; ++j) {
                if (i == j) continue;
                if (mask & (1 << j)) {
                    tmpCost += cost[i][j];
                }
            }

            ans = min(ans, solve(mask | (1 << i), cst + tmpCost));
        }
    }

    return ans;
}

int main() {

    //freopen("in.txt", "r", stdin);

    int i, j;
    scanf("%d", &test);
    for (t = 1; t <= test; ++t) {

        scanf("%d", &n);
        for (i = 0; i < n; ++i) {
            for (j = 0; j < n; ++j) {
                scanf("%d", &cost[i][j]);
            }
        }

        target = (1 << n) - 1;

        memset(bitmask, -1, sizeof(bitmask));

        printf("Case %d: %d\n", t, solve(0, 0));

    }

    return (0);
}