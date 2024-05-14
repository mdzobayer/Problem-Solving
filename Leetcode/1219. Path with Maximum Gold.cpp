class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int maxGold = 0, i, j;

        for (i = 0; i < rows; ++i) {
            for (j = 0; j < cols; ++j) {
                maxGold = max(maxGold, dfsBacktrack(grid, rows, cols, i, j));
            }
        }

        return maxGold;
    }

    const vector<int> dirs = {0, 1, 0, -1, 0};

    int dfsBacktrack(vector< vector<int> >& grid, int rows, int cols, int row, int col) {
        if (row < 0 || col < 0 || row == rows || col == cols || grid[row][col] == 0) return 0;

        int maxGold = 0;
        int originalValue = grid[row][col];
        grid[row][col] = 0;

        for (int dir = 0; dir < 4; ++dir) {
            maxGold = max(maxGold, dfsBacktrack(grid, rows, cols, dirs[dir] + row, dirs[dir + 1] + col));
        } 

        grid[row][col] = originalValue;
        return maxGold + originalValue;
    }
};