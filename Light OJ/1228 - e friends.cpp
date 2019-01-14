#include <bits/stdc++.h>
#define ll long long int
#define SIZE 15
using namespace std;

int n, k, q, target, allow;
bool enemy[SIZE][SIZE];

int dp[8200][SIZE]; // Memorization

int solve ( int mask, int p, int co) {
    // Base case
    if (mask == target || allow < co) return (0);

    // Memorization
    if (dp[mask][p] != -1) return dp[mask][p];

    int & ans = dp[mask][p];
    ans = 0;
    int i;

    for (i = 1; i <= n; ++i) {
        if ((mask & (1 << i)) == 0) {
            if(enemy[p][i])
                ans += (1 + solve(mask | (1 << i), i, co + k));
            else
                ans += solve(mask | (1 << i), i, co);
        }
    }
    return ans;
}


int main() {

    //freopen("in.txt", "r", stdin);

    int test, t, i, x, j, y, r;

    scanf("%d", &test);
    for (t = 1; t <= test; ++t) {


        scanf("%d %d %d", &n, &k, &q);
        // Clear enemy and input again
        memset(enemy, false, sizeof(enemy));
        for (i = 1; i <= n; ++i) {
            scanf("%d", &x);
            for (j = 0; j < x; ++j) {
                scanf("%d", &y);
                enemy[i][y] = true;
            }
        }
        target = (1 << (n + 1)) - 1;

        printf("Case %d:\n", t);
        // Process with query
        for (i = 0; i < q; ++i) {
            scanf("%d", &r);
            allow = r;  // Calculate allowing k
            memset(dp, -1, sizeof(dp)); // Clear dp memory

            printf("%d\n", solve(1, 0, 0));
        }
    }

    return (0);
}
