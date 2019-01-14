#include <bits/stdc++.h>
#define SIZE 55
#define MAX 1000+5

using namespace std;

int coin[SIZE], ava[SIZE], n, k;

int dp[SIZE][MAX];

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

    int i, ans = 0, val = 0;

    for (i = 0; i < ava[index] && (need - val >= 0); ++i) {
        val += coin[index];
        ans += solve(index + 1, need - val);
        ans %= 100000007;
    }

    ans += solve(index + 1, need);
    ans %= 100000007;

    return dp[index][need] = ans;
}

int main() {

    //freopen("in.txt", "r", stdin);

    int test, t, i;
    scanf("%d", &test);
    for (t = 1; t <= test; ++t) {

        scanf("%d %d", &n, &k);
        //cout << n << " " << k << endl;

        for (i = 0; i < n; ++i) {
            scanf("%d", &coin[i]);
            //cout << coin[i] << " ";
        }
        for (i = 0; i < n; ++i) {
            scanf("%d", &ava[i]);
            //cout << ava[i] << " ";
        }
        //cout << endl;

        memset(dp, -1, sizeof(dp));
        printf("Case %d: %d\n", t, solve(0, k));
    }


    return (0);
}
