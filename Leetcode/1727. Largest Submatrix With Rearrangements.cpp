class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int i, j, k, m, n, ans = 0;

        m = matrix.size();
        n = matrix[0].size();

        for (i = 0; i < m; ++i) {
            for (j = 0; j < n; ++j) {
                if (matrix[i][j] != 0 && i > 0) {
                    matrix[i][j] += matrix[i - 1][j];
                }
            }

            vector<int> currentRow = matrix[i];
            sort(currentRow.begin(), currentRow.end(), greater<int>());
            for (k = 0; k < n; ++k) {
                if (currentRow[k] == 0) break;

                ans = max(ans, currentRow[k] * (k + 1));
            }
        }

        return ans;
    }
};