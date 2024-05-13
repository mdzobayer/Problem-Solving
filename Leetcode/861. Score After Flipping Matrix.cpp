class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int i, j, m = grid.size(), n = grid[0].size();

        // First column
        for (i = 0; i < m; ++i) {
            if (grid[i][0] == 0) {
                for (j = 0; j < n; ++j) {
                    grid[i][j] = 1 - grid[i][j];
                }
            }
        }

        for (j = 1; j < n; ++j) {
            int countZero = 0;

            for (i = 0; i < m; ++i) {
                if (grid[i][j] == 0) ++countZero;
            }

            if (countZero > m - countZero) {
                for (i = 0; i < m; ++i) {
                    grid[i][j] = 1 - grid[i][j];
                }
            }
        }

        int ans = 0;

        for (i = 0; i < m; ++i) {
            for (j = 0; j < n; ++j) {
                ans += (grid[i][j] << (n - j - 1));
            }
        }

        return ans;
    }
};