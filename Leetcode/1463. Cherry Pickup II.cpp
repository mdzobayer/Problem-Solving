class Solution {
    int dp[71][71][71];
    int m, n;
public:
    int cherryPickup(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        memset(dp, -1, sizeof(dp));

        return solve(0, 0, n - 1, grid);
    }

    int solve(int row, int col1, int col2, vector<vector<int>>& grid) {
        if (col1 < 0 || col1 >= n || col2 < 0 || col2 >= n) {
            return 0;
        }

        if (dp[row][col1][col2] != -1) return  dp[row][col1][col2];

        int ans = 0, maximum = 0, newCol1, newCol2;
        ans += grid[row][col1];
        if (col1 != col2) ans += grid[row][col2];

        if (row < m - 1) {
            for (newCol1 = col1 - 1; newCol1 < col1 + 2; ++newCol1) {
                for (newCol2 = col2 - 1; newCol2 < col2 + 2; ++newCol2) {
                    maximum = max(maximum, solve(row + 1, newCol1, newCol2, grid));
                }
            }
        }

        return dp[row][col1][col2] = ans + maximum;
    }
};