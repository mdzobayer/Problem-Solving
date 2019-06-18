#include <bits/stdc++.h>

using namespace std;
int dp[55][55][55];

string s1, s2, s3;

int solve(int x, int y, int z) {
    if (x < 0 || y < 0 || z < 0) return (0);

    if (dp[x][y][z] != -1) {
        return dp[x][y][z];
    }

    int ans = 0;

    if (s1[x] == s2[y] && s2[y] == s3[z]) {
        ans = max(ans, 1 + solve(x - 1, y - 1, z - 1));
    }
    else {
        // X
        ans = max(ans, solve(x, y - 1, z - 1));
        ans = max(ans, solve(x, y, z - 1));
        ans = max(ans, solve(x, y - 1, z));

        // Y
        ans = max(ans, solve(x - 1, y, z - 1));
        ans = max(ans, solve(x, y, z - 1));
        ans = max(ans, solve(x - 1, y, z));

        // Z
        ans = max(ans, solve(x - 1, y - 1, z));
        ans = max(ans, solve(x - 1, y, z));
        ans = max(ans, solve(x, y - 1, z));
    }
    ans = max(ans, solve(x - 1, y - 1, z - 1));

    return dp[x][y][z] = ans;
}

int main() {

    //freopen("in.txt", "r", stdin);

    int test, t;
    cin >> test;
    for (t = 1; t <= test; ++t) {
        cin.ignore();
        cin >> s1 >> s2 >> s3;

        memset(dp, -1, sizeof(dp));

        printf("Case %d: %d\n", t, solve(s1.size() - 1, s2.size() - 1, s3.size() - 1));
    }

    return (0);
}