#include <bits/stdc++.h>
#define SIZE 110
using namespace std;

char str1[SIZE], str2[SIZE];
int dp[SIZE][SIZE];

int lcs(int x, int y) {
    if (x < 0 || y < 0) return 0;

    if (dp[x][y] != -1) {
        return dp[x][y];
    }
    if (str1[x] == str2[y]) {
        dp[x][y] = 1 + lcs(x - 1, y - 1);
    }
    else {
        dp[x][y] = max(lcs(x-1, y), lcs(x, y-1));
    }
    return dp[x][y];
}

int main() {

    //freopen("in.txt", "r", stdin);

    int test = 0, ans, x, y;
    while(gets(str1)) {
        if (strcmp(str1, "#") == 0) {
            break;
        }
        gets(str2);

        memset(dp, -1, sizeof(dp));
        x = strlen(str1);
        y = strlen(str2);
        ans = lcs(x - 1, y - 1);

        printf("Case #%d: you can visit at most %d cities.\n", ++test, ans);
    }

    return (0);
}
