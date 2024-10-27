class Solution {
    vector< vector<int> >dp;
public:
    int countSquares(vector<vector<int>>& grid) {
        int ans = 0;

        dp.resize(grid.size(), vector<int>(grid[0].size(), -1));
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                ans += solve(i, j, grid);
            }
        }

        return ans;
    }

    int solve(int i, int j, vector< vector<int> > &grid) {
        if (i >= grid.size() || j >= grid[0].size()) return 0;
        if (grid[i][j] == 0) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        int right = solve(i, j + 1, grid);
        int diagonal = solve(i + 1, j + 1, grid);
        int below = solve(i + 1, j, grid);

        return dp[i][j] = 1 + min(right, min(diagonal, below));
    }
};