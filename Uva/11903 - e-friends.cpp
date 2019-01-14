#include <bits/stdc++.h>
#define ll long long int
#define SIZE 15
using namespace std;

int n, k, q, target, allow;
bool enemy[SIZE][SIZE];

int dp[8200][SIZE][SIZE]; // Memorization

int solve ( int mask, int p, int co) {
    // Base case
    if (0 > co) return (0);
    if(mask == target) return 1;

    // Memorization
    if (dp[mask][p][co] != -1) return dp[mask][p][co];

    int & ans = dp[mask][p][co];
    ans = 0;
    int i;

    for (i = 1; i <= n; ++i) {
        if ((mask & (1 << i)) == 0) {
            if(enemy[p][i])
                ans += solve(mask | (1 << i), i, co - 1);
            else
                ans += solve(mask | (1 << i), i, co);
        }
    }

    return ans;
}

int fact(int nx) {
    int res = 1;
    while(nx > 1) {
        res *= nx;
        --nx;
        //cerr << "here" << endl;
    }
    return res;
}


int main() {

    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int test, t, i, x, j, y, r;

    scanf("%d", &test);
    for (t = 1; t <= test; ++t) {
        memset(dp, -1, sizeof(dp));

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
            //printf("K = %d r = %d\n", k, r);
            if (k == 0) {
                printf("%d\n", fact(n));
            }
            else {
                allow = r / k;  // Calculate allowing k
                //memset(dp, -1, sizeof(dp)); // Clear dp memory

                printf("%d\n", solve(1, 0, min(n-1,allow)));
            }
        }
    }

    return (0);
}
