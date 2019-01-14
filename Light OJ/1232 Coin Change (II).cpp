#include <bits/stdc++.h>
#define SIZE 105
#define MAX 10000+5

using namespace std;

int coin[SIZE], n, k, dp[MAX];
/*
int solve(int index, int need) {
    //printf("Entering %d Need %d\n", index, need);
    if (need < 0 || index > n) return (0);

    if(need == 0) {
        //cout << "filled" << endl;
            return 1;
    }
    if(dp[index][need] != -1) {
        return dp[index][need];
    }

    int i, ans = 0, val = 0, sub;

    for (i = 0; i < k; ++i) {
        val += coin[index];
        sub = need - val;
        if(sub >= 0) {
            ans += solve(index + 1, sub);
            ans %= 100000007;
        }
        else break;
    }

    ans += solve(index + 1, need);
    ans %= 100000007;

    return dp[index][need] = ans;
}
*/

int solve() {
    int i, j;
    dp[0] = 1;
    for (i = 0; i < n; ++i) {
        for (j = 1; j <= k; ++j) {
            if(coin[i] <= j) {
                dp[j] += dp[j - coin[i]];
                dp[j] %= 100000007;
            }
        }
    }

    return dp[k];
}
int main() {

    //freopen("in.txt", "r", stdin);

    int test, t, i, j;
    scanf("%d", &test);
    for (t = 1; t <= test; ++t) {

        scanf("%d %d", &n, &k);
        //cout << n << " " << k << endl;

        for (i = 0; i < n; ++i) {
            scanf("%d", &coin[i]);
            //cout << coin[i] << " ";
        }

        memset(dp, 0, sizeof(dp));

        printf("Case %d: %d\n", t, solve());
//        for (i = 0; i < k; ++i) {
//            for (j = 0; j < n; ++j) {
//                printf("%d ", dp[j][i]);
//            }
//            puts("");
//        }
    }


    return (0);
}
