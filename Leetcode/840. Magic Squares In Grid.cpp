class Solution {
    
    int m, n;
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int i, j, count = 0;
        m = grid.size(), n = grid[0].size();

        for (i = 0; i < m - 2; ++i) {
            for (j = 0; j < n - 2; ++j) {
                count += isMagicGrid(grid, i, j) ? 1 : 0;
            }
        }
        
        return count;
    }

    bool isMagicGrid(vector<vector<int>>& grid, int x, int y) {
        vector<bool> available(10, false);
        vector<int> sums(8, 0);

        int i;
        for(i = 0; i < 3; ++i) {
            // All row sum
            sums[0] += grid[x][y + i];
            available[grid[x][y + i]] = true;
            sums[1] += grid[x + 1][y + i];
            available[grid[x + 1][y + i]] = true;
            sums[2] += grid[x + 2][y + i];
            available[grid[x + 2][y + i]] = true;

            // All column sum
            sums[3] += grid[x + i][y];
            available[grid[x + i][y]] = true;
            sums[4] += grid[x + i][y + 1];
            available[grid[x + i][y + 1]] = true;
            sums[5] += grid[x + i][y + 2];
            available[grid[x + i][y + 2]] = true;

            sums[6] += grid[x + i][y + i];
        }

        sums[7] = grid[x + 2][y] + grid[x + 1][y + 1] + grid[x][y + 2];

        for (i = 1; i < 8; ++i) {
            if (sums[i] != sums[i - 1]) return false;
        }

        for (i = 1; i < 10; ++i) {
            if (!available[i]) return false;
        }

        return true;
    }
};