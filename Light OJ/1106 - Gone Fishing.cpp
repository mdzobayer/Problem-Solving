#include <bits/stdc++.h>
#define N 30
#define TIME 200
using namespace std;

int n, h, maxTime, fishes[N], decreRate[N], movingCost[N], dp[N][TIME][TIME];
bool flag;

int solve(int lakeNo, int totalTime, int spendTime) {
    if (totalTime >= maxTime) return (0);

    if (dp[lakeNo][totalTime][spendTime] != -1) 
        return dp[lakeNo][totalTime][spendTime];

    int ans = 0;
    int availableFish = fishes[lakeNo] - (decreRate[lakeNo] * spendTime);

    if (availableFish < 0) availableFish = 0;
    ans += solve(lakeNo, totalTime + 1, spendTime + 1) + availableFish;

    int ans2;
    if (lakeNo < n) {
        ans2 =  max(ans, solve(lakeNo + 1, totalTime + movingCost[lakeNo] ,0));
    }
    else {
        ans2 = ans;
    }
    //printf("Lake no %d maxFish %d\n", lakeNo, ans2);

    return dp[lakeNo][totalTime][spendTime] = ans2;
}

void PrintPath(int lakeNo, int totalTime, int spendTime) {

    int availableFish;

    int moveTime = 0;
    if (lakeNo < n)
        moveTime = movingCost[lakeNo];

    if (totalTime < maxTime && (spendTime + moveTime) < maxTime) {
        
        availableFish = fishes[lakeNo] - (decreRate[lakeNo] * spendTime);
        if (availableFish < 0) 
            availableFish = 0;
        printf("\nlake %d Check %d %d\n", lakeNo, dp[lakeNo][totalTime][spendTime], availableFish + dp[lakeNo][totalTime + 1][spendTime + 1]);
        
        if (availableFish + dp[lakeNo][totalTime + 1][spendTime + 1] == dp[lakeNo][totalTime][spendTime]) {
            PrintPath(lakeNo, totalTime + 1, spendTime + 1);
        }
        else {
            if (flag)
                printf(", %d", spendTime);
            else printf("%d", spendTime);

            flag = true;

            if (lakeNo < n) {
                PrintPath(lakeNo + 1, totalTime + movingCost[lakeNo], 0);
            }
        }
    }

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
        ans = solve(1, 0, 0);

        printf("Case %d:\n", t);
        PrintPath(1, 0, 0);
        printf("\nNumber of fish expected: %d\n", ans);


    }

    return (0);
}