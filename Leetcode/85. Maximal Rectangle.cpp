class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int i, j, k, area, maxArea = 0, m = matrix.size(), n = matrix[0].size();

        vector<int> dpRow(n, 0);
        vector<vector<int>> dp(m, dpRow);

        for (i = 0; i < m; ++i) {
            for (j = 0; j < n; ++j) {
                if (matrix[i][j] == '1') {
                    dp[i][j] = j == 0 ? 1 : dp[i][j - 1] + 1;

                    area = dp[i][j];

                    for (k = i; k >= 0; --k) {
                        area = min(area, dp[k][j]);

                        maxArea = max(maxArea, area * (i - k + 1));
                    }
                }
            }
        }

        return maxArea;
    }
};