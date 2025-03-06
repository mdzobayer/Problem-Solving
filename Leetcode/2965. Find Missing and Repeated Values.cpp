class Solution {
    public:
        vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
            int i, j, n = grid.size();
            vector<int> freq(n*n + 1, 0), ans(2, 0);
    
            for (i = 0; i < n; ++i) {
                for (j = 0; j < n; ++j) {
                    ++freq[grid[i][j]];
                }
            }
    
            for (i = 1; i <= n * n; ++i) {
                if (freq[i] == 0) {
                    ans[1] = i;
                }
                else if (freq[i] == 2) {
                    ans[0] = i;
                }
            }
    
            return ans;
        }
    };