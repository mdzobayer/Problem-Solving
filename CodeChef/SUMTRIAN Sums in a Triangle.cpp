#include <bits/stdc++.h>

using namespace std;

vector < int > tri[1000+5];

int dp[1000+5][1000+5];

int mx, n;

int solve(int r, int c) {
    if (r > n || c >= n) {
        return 0;
    }

    if (dp[r][c] != -1) {
        return dp[r][c];
    }

    int ans1 = 0, ans2 = 0;
    ans1 = solve(r+1, c) + tri[r][c];
    ans2 = solve(r+1, c+1) + tri[r][c];

    return dp[r][c] = max(ans1, ans2);
}

int main() {

    int test, t, i, x, j;
    cin >> test;
    for (t = 0; t < test; ++t) {
        cin >> n;

        for (i = 0; i <= n+2; ++i) {
            tri[i].clear();
        }

        for (i = 1; i <= n; ++i) {
            for (j = 0; j < i; ++j) {
                scanf("%d", &x);
                tri[i].push_back(x);
            }
        }
        memset(dp, -1, sizeof(dp));
        cout << solve(1, 0) << endl;
    }

    return (0);
}