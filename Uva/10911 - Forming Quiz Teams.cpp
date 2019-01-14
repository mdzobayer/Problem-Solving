#include <bits/stdc++.h>


using namespace std;

int x[20], y[20];

double dis[20][20];
double dp[1 << 16];

int target, n;

double bitMask(int mask) {

    if (dp[mask] > -1.0) return dp[mask];

    if (mask == target) {
        return dp[mask] = 0.0;
    }
    int x1, x2;
    double ans = DBL_MAX;
    for (x1 = 0; x1 < (n*2); ++x1) {
        if ((mask & (1 << x1)) == 0) {
            break;
        }
    }

    for (x2 = x1 + 1; x2 < (n*2); ++x2) {
        if ((mask & (1 << x2)) == 0) {
            ans = min (ans,
                       dis[x1][x2] + bitMask(mask | (1 << x2) | (1 << x1)));
        }
    }

    return dp[mask] = ans;
}


int main() {

    //freopen("in.txt","r", stdin);

    int i, j, t = 0;

    while(scanf("%d", &n) == 1) {
        if (n == 0) break;

        for (i = 0; i < n*2; ++i) {
            scanf("%*s %d %d", &x[i], &y[i]);
        }

        for (i = 0; i < 2 * n - 1; ++i) {
            for (j = i + 1; j < n * 2; ++j) {
                dis[j][i] = dis[i][j] = hypot(x[i] - x[j], y[i] - y[j]);
            }
        }
        target = (1 << (2 * n)) - 1;
        for (i = 0; i < (1 << 16); ++i) {
            dp[i] = -1.0;
        }
        //cout << bitMask(0) << endl;
        printf("Case %d: %0.2f\n",++t, bitMask(0));
    }

    return (0);
}
