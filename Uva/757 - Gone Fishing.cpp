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

    for (spendTime = 0; spendTime <= remainTime; ++spendTime) {

        if (spendTime == 0) {
            ans = max(ans, solve(lakeNo + 1, remainTime - movingCost[lakeNo]));
        }
        else {
            availableFish = fishes[lakeNo] - (decreRate[lakeNo] * (spendTime - 1));
            if (availableFish < 0) availableFish = 0;

            found += availableFish;
//            if (lakeNo == 2) {
//                printf("found is %d\n", found);
//            }

            ans = max(ans, found + solve(lakeNo + 1, (remainTime - spendTime) - movingCost[lakeNo]));

        }

    }
    //printf("lakeNo %d ans %d\n", lakeNo, ans);
    return dp[lakeNo][remainTime] = ans;
}

void PrintPath(int lakeNo, int remainTime) {
    //printf("Lake no %d time %d\n", lakeNo, remainTime);
    if (lakeNo > n) return;

    if (remainTime < 0) remainTime = 0;


    int tm = 0, ans = 0;

    int spendTime, found = 0, availableFish;

    for (spendTime = 0; spendTime <= remainTime; ++spendTime) {

        if (spendTime == 0) {
            if (ans <= solve(lakeNo + 1, remainTime - movingCost[lakeNo])) {
                ans = solve(lakeNo + 1, remainTime - movingCost[lakeNo]);
                tm = spendTime;
            }
        }
        else {
            availableFish = fishes[lakeNo] - (decreRate[lakeNo] * (spendTime - 1));
            if (availableFish < 0) availableFish = 0;

            found += availableFish;

            if(ans <= found + solve(lakeNo + 1, (remainTime - spendTime) - movingCost[lakeNo])) {
                ans = found + solve(lakeNo + 1, (remainTime - spendTime) - movingCost[lakeNo]);
                tm = spendTime;
            }

        }

    }


    if (lakeNo == 1) {
        printf("%d", tm * 5);
    }
    else {
        printf(", %d", tm * 5);
    }
    //printf(", %d", tm * 5);
    PrintPath(lakeNo + 1, remainTime - tm - movingCost[lakeNo]);
}


int main() {

    // freopen("in.txt", "r", stdin);

    int test, t = 0, i, ans;

    while(scanf("%d", &n) == 1){
        if (n == 0) break;

        scanf("%d", &h);

        maxTime = (60 * h) / 5;

        for (i = 1; i <= n; ++i) {
            scanf("%d", &fishes[i]);
        }

        for (i = 1; i <= n; ++i) {
            scanf("%d", &decreRate[i]);
        }

        memset(movingCost, 0, sizeof(movingCost));
        for (i = 1; i < n; ++i) {
            scanf("%d", &movingCost[i]);
        }

        memset(dp, -1, sizeof(dp));
        ans = solve(1, maxTime);

        //printf("Case %d:\n", t);
        if (t > 0) puts("");
        PrintPath(1, maxTime);

        printf("\nNumber of fish expected: %d\n", ans);
        ++t;
    }

    return (0);
}