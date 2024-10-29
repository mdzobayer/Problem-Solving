class Solution {
    int m, n;
    vector<int> dirs{-1, 0, 1};
    vector< vector<int> > dp;
public:
    int maxMoves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        dp.resize(m, vector<int>(n, -1));

        int ans = 0;

        for (int i = 0; i < m; ++i) {
            ans = max(ans, solve(grid, i, 0));
        }

        return ans;
    }

    int solve(vector<vector<int>>& grid, int x, int y) {
        if (dp[x][y] != -1) return dp[x][y];

        int ans = 0;

        for (int dir : dirs) {
            int nextX = x + dir;
            int nextY = y + 1;

            if (nextX >= 0 && nextY >= 0 && nextX < m && nextY < n && grid[nextX][nextY] > grid[x][y]) {
                ans = max(ans, solve(grid, nextX, nextY) + 1);
            }
        }

        return dp[x][y] = ans;
    }
};