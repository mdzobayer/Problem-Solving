#include <bits/stdc++.h>
#define N 30
#define TIME 200
using namespace std;

int n, h, xTime, maxTime, fishes[N], decreRate[N], movingCost[N], dp[N][TIME];
bool flag;

int solve(int lakeNo, int remainTime) {
    
    if (remainTime <= 0 || lakeNo > n) return (0);
    //printf("Lake no : %d RemainTime : %d\n", lakeNo, remainTime);

    if (dp[lakeNo][remainTime] != -1) {
        return dp[lakeNo][remainTime];
    }

    int spendTime, availableFish, found = 0, ans = 0;

    for (spendTime = 0; spendTime < remainTime; ++spendTime) {

        availableFish = fishes[lakeNo] - (decreRate[lakeNo] * spendTime);
        xTime = remainTime - (1 + spendTime + movingCost[lakeNo]);

        if (availableFish < 0) availableFish = 0;

        //if (xTime > 0) {
            ans = max(ans, solve(lakeNo + 1, xTime) + availableFish + found);
        //}
        //else {
            //ans = max(ans, availableFish + found);
        //}
        found += availableFish;
    }

    return dp[lakeNo][remainTime] = ans;
}

void PrintPath(int lakeNo, int remainTime) {
    //printf("Lake no %d time %d\n", lakeNo, remainTime);
    if (lakeNo > n) return;
    int tm = 0, t, ans = 0;
    for (t = 0; t < remainTime; ++t) {
        if (dp[lakeNo][t] >= ans) {
            ans = dp[lakeNo][t];
            tm = t;
        }
    }
    if (lakeNo == 1) {
        printf("%d", (tm));
    }
    else {
        printf(", %d", (tm));
    }
    //printf(", %d", tm * 5);
    PrintPath(lakeNo + 1, remainTime - (tm + 1));
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
        PrintPath(1, maxTime);
        printf("\nNumber of fish expected: %d\n", ans);
    }

    return (0);
}