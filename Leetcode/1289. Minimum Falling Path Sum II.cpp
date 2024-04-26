class Solution {
    vector<vector<int>> dp;
    vector<vector<bool>> visited;
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int i, ans = INT_MAX;
        int m = grid.size(), n = grid[0].size();

        dp.resize(m, vector<int>(n, 0));
        visited.resize(m, vector<bool>(n, false));

        for (i = 0; i < grid[0].size(); ++i) {
            ans = min(ans, solve(grid, 0, i));
        }

        return ans;
    }

    int solve(vector<vector<int>>& grid, int x, int y) {
        if (x >= grid.size() || y < 0 || y >= grid[0].size()) return 0;

        if (visited[x][y]) return dp[x][y];

        int ans = INT_MAX;

        for (int i = 0; i < grid[x].size(); ++i) {
            if (i != y) {
                ans = min(ans, solve(grid, x + 1, i));
            }
        }
        
        if (ans == INT_MAX) {
            ans = 0;
        }

        visited[x][y] = true;

        return dp[x][y] = ans + grid[x][y];
    }
};