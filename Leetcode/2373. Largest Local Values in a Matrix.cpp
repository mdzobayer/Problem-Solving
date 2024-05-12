class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int i, j, k, l, n = grid.size();

        vector< vector<int> > ans(n - 2, vector<int>(n - 2, 0));

        for (i = 0; i < n - 2; ++i) {
            for (j = 0; j < n - 2; ++j) {
                ans[i][j] = grid[i][j];
                for (k = i; k < i + 3; ++k) {
                    for (l = j; l < j + 3; ++l) {
                        ans[i][j] = max(ans[i][j], grid[k][l]);
                    }
                }
            }
        }

        return ans;
    }
};