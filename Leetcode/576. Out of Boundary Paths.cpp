class Solution {
    int dp[51][51][51];
    int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int m, n, maxMove;
    int mod = 1e9 + 7;
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp, -1, sizeof(dp));
        this->m = m;
        this->n = n;
        this->maxMove = maxMove;

        return solve(startRow, startColumn, 0);
    }

    int solve(int x, int y, int moveCount) {
        if (moveCount > maxMove) return 0;

        if (x < 0 || y < 0 || x >= m || y >= n) {
            return 1;
        }

        if (dp[x][y][moveCount] != -1) return dp[x][y][moveCount];

        int ans = 0;

        for (int i = 0; i < 4; ++i) {
            ans += (solve(x + dir[i][0], y + dir[i][1], moveCount + 1)) % mod;
            ans %= mod;
        }

        return dp[x][y][moveCount] = ans;
    }

};