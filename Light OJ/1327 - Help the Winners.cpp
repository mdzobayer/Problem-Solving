#include <bits/stdc++.h>
#define SIZE 20
using namespace std;

int target, dp[(1 << 16)+5][SIZE], arr[SIZE][SIZE], n;

int bitmask(int mask, int dress) {

    if(mask == target && dress == n) return 1;
    if(mask == target || dress >= n) return 0;

    if(dp[mask][dress] != -1) return dp[mask][dress];
    //puts("Debug 1");
    int i, ans = 0;
    for (i = 0; i < n; ++i) {
        if(arr[dress][i] > 0 && (mask & (1 << i)) == 0) {
            //printf("Called Someone\n");
            ans += bitmask((mask | (1 << i)), dress + 1);

        }
    }

    return dp[mask][dress] = ans;
}

int main() {
    //puts("Debug 0");
    freopen("in.txt", "r", stdin);

    int test, t, i, j;
    scanf("%d", &test);
    for (t = 1; t <= test; ++t) {
        scanf("%d", &n);
        for (i = 0; i < n; ++i) {
            for (j = 0; j < n; ++j)
                scanf("%d", &arr[i][j]);
        }
        target = (1 << n) - 1;

        memset(dp, -1, sizeof(dp));
        //puts("Debug 1");
        printf("Case %d: %d\n", t, bitmask(0, 0));
    }

    return (0);
}
