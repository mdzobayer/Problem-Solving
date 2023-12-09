class Solution {
    int dp[100][100];
    int m, n;
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();

        memset(dp, -1, sizeof(dp));

        return solve(0, 0, obstacleGrid);
    }

    int solve(int x, int y, vector<vector<int>>& obstacleGrid) {
        if (x >= m || y >= n) return 0;
        if (obstacleGrid[x][y] == 1) return 0;
        if (x == m - 1 && y == n - 1) return 1;

        if(dp[x][y] != -1) return dp[x][y];

        int ans = 0, way1, way2;

        way1 = solve(x + 1, y, obstacleGrid);
        way2 = solve(x, y + 1, obstacleGrid);
        ans = way1 + way2;

        return dp[x][y] = ans;
    }
};