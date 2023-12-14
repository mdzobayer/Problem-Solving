class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int i, j;

        vector<int> onesRow(m, 0), onesCol(n, 0), zerosRow(m, 0), zerosCol(n, 0);
        vector<vector<int>> diff;

        for (i = 0; i < m; ++i) {
            for (j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    onesRow[i] += 1;
                    onesCol[j] += 1;
                }
                else {
                    zerosRow[i] += 1;
                    zerosCol[j] += 1;
                }
            }
        }

        for (i = 0; i < m; ++i) {
            vector<int> diffRow(n, 0);
            for (j = 0; j < n; ++j) {
                diffRow[j] = onesRow[i] + onesCol[j] - zerosRow[i] - zerosCol[j];
            }

            diff.push_back(diffRow);
        }

        return diff;
    }
};