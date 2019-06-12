#include <bits/stdc++.h>
#define N 30
#define TIME 200
using namespace std;

int n, h, xTime, maxTime, fishes[N], decreRate[N], movingCost[N], dp[N][TIME][TIME];
bool flag;

int solve(int lakeNo, int remainTime) {
    
    if (remainTime <= 0 || lakeNo > n) return (0);
    //printf("Lake no : %d RemainTime : %d\n", lakeNo, remainTime);
    int spendTime, availableFish, found = 0, ans = 0;

    for (spendTime = 0; (remainTime - spendTime) > 0; ++spendTime) {

        availableFish = fishes[lakeNo] - (decreRate[lakeNo] * spendTime);
        xTime = remainTime - (spendTime + movingCost[lakeNo]);

        if (availableFish < 0) availableFish = 0;

        if (xTime > 0) {
            ans = max(ans, solve(lakeNo + 1, xTime) + availableFish + found);
        }
        else {
            ans = max(ans, availableFish + found);
        }
        found += availableFish;
    }

    return ans;
}


int main() {

    freopen("in.txt", "r", stdin);

    int test, t, i, ans;
    scanf("%d", &test);
    for (t = 1; t <= test; ++t) {
        scanf("%d %d", &n, &h);

        maxTime = (60 * h) / 5;
        
        for (i = 1; i <= n; ++i) {
            scanf("%d", &fishes[i]);
        }

        for (i = 1; i <= n; ++i) {
            scanf("%d", &decreRate[i]);
        }

        for (i = 1; i < n; ++i) {
            scanf("%d", &movingCost[i]);
        }
        
        memset(dp, -1, sizeof(dp));
        flag = false;
        ans = solve(1, maxTime);

        printf("Case %d:\n", t);
        //PrintPath(1, 0, 0);
        printf("\nNumber of fish expected: %d\n", ans);
    }

    return (0);
}