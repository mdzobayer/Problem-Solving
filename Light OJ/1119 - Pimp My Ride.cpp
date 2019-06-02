#include <bits/stdc++.h>

using namespace std;
#define SIZE 20
#define ll long long int
int test, t, n, cost[SIZE][SIZE], target;

ll bitmask[(1 << 14) + 5];

ll solve (int mask) {

    if (mask == target){ 
        //cout << "Target Filled" << endl;
        return 0;
    }

    if (bitmask[mask] != -1) return bitmask[mask];

    ll i, j, tmpCost, ans = LLONG_MAX;

    for (i = 0; i < n; ++i) {
        if ((mask & (1 << i)) == 0) {
            tmpCost = cost[i][i];
            for (j = 0; j < n; ++j) {
                if (i == j) continue;
                if (mask & (1 << j)) {
                    tmpCost += cost[i][j];
                }
            }

            ans = min(ans, solve((mask | (1 << i))) + tmpCost);
        }
    }

    return bitmask[mask] = ans;
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

        printf("Case %d: %lld\n", t, solve(0));

    }

    return (0);
}