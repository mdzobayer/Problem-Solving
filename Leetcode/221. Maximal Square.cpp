class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int ans = 0, i, j, m = matrix.size(), n = matrix[0].size();

        vector<int> row(n, 0);
        vector<vector<int>> dp;

        for (i = 0; i < m; ++i) {
            dp.push_back(row);
            for (j = 0; j < n; ++j) {
                if (matrix[i][j] == '1' && i > 0 && j > 0) {
                    dp[i][j] = min(dp[i][j - 1], dp[i - 1][j]);
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]) + 1;
                }
                else if (matrix[i][j] == '1') dp[i][j] = 1;
                
                ans = max(ans, dp[i][j]);
                
            }
        }
        return ans * ans;
    }
};