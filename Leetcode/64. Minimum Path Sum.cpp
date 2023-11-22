class Solution {
    int m, n;
    int dp[205][205];
public:
    int minPathSum(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        memset(dp, -1, sizeof(dp));

        return solve(0, 0, grid);
    }

    int solve(int x, int y, vector<vector<int>>& grid) {

        if (dp[x][y] != -1) return dp[x][y];
        
        int ans = INT_MAX;
        if (isValid(x + 1, y)) {
            ans = min(ans, solve(x + 1, y, grid));
        }
        if (isValid(x, y + 1)) {
            ans = min(ans, solve(x, y + 1, grid));
        }

        if (ans < INT_MAX) ans += grid[x][y];
        else ans = grid[x][y];

        return dp[x][y] = ans;
    }

    int isValid(int x, int y) {
        if (x >= m || y >= n) return false;

        return true;
    }
};