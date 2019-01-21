#include <bits/stdc++.h>


using namespace std;

int arr[25], dp[25][20000+5], t, N;

int subsetSum(int i, int remain) {
    if(remain <= 0 || i >= t)
        return 0;


    if(dp[i][remain] != -1) {
        return dp[i][remain];
    }

    int y, x;
    x = y = 0;
    x = subsetSum(i + 1, remain);
    if(remain >= arr[i]) {
        y = subsetSum(i + 1, remain - arr[i]) + arr[i];
    }

    return dp[i][remain] = max(x, y);
}

void printPath(int i, int remain) {
    if(remain <= 0 || i >= t)
        return;

    int x, y;
    x = y = 0;
    x = subsetSum(i + 1, remain);
    if(remain >= arr[i]) {
        y = subsetSum(i + 1, remain - arr[i]) + arr[i];
    }

    if(x >= y) {
        printPath(i + 1, remain);
    }
    else {
        printf("%d ", arr[i]);
        printPath(i + 1, remain - arr[i]);
    }
}

int main() {

    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int i, ans;
    while(scanf("%d %d", &N, &t) == 2) {
        for (i = 0; i < t; ++i) {
            scanf("%d", &arr[i]);
        }
        memset(dp, -1, sizeof(dp));

        ans = subsetSum(0, N);
        printPath(0, N);
        printf("sum:%d\n", ans);
/*
        for (i = 0; i < t; ++i) {
            for (int j = 0; j < N; ++j) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
*/
    }

    return (0);
}
