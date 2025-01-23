class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int i, j, ans = 0, m = grid.size(), n = grid[0].size();
        vector<int> rows(m, 0), columns(n, 0);

        for (i = 0; i < m; ++i) {
            for (j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    ++ rows[i];
                    ++ columns[j];
                }
            }
        }

        for (i = 0; i < m; ++i) {
            for (j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    if (rows[i] > 1 || columns[j] > 1) {
                        ++ ans;
                    }
                }
            }
        }

        return ans;
    }
};