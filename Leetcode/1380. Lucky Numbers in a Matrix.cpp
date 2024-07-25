class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int i, j, m = matrix.size(), n = matrix[0].size();

        vector<int> rowMin(m, INT_MAX), columnMax(n, INT_MIN);

        for (i = 0; i < m; ++i) {
            for (j = 0; j < n; ++j) {
                rowMin[i] = min(rowMin[i], matrix[i][j]);
                columnMax[j] = max(columnMax[j], matrix[i][j]);
            }
        }

        vector<int> ans;
        for (i = 0; i < m; ++i) {
            for (j = 0; j < n; ++j) {
                if (matrix[i][j] == rowMin[i] && matrix[i][j] == columnMax[j]) {
                    ans.push_back(matrix[i][j]);
                }
            }
        }

        return ans;
    }
};