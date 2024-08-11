class Solution {
    int rows, cols;
    vector< vector<int> > directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
public:
    int minDays(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();

        int initialIsLand = countIsLand(grid);
        if (initialIsLand != 1) return 0;

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 0) continue;

                // Temporarily change to water
                grid[i][j] = 0;
                int newIsLandCount = countIsLand(grid);

                // If disconnected
                if (newIsLandCount != 1) return 1;

                // Revert change
                grid[i][j] = 1;
            }
        }

        return 2;
    }

    int countIsLand(vector< vector<int> > & grid) {
        vector< vector<bool> > visited(rows, vector<bool>(cols, false));
        int isLandCount = 0;

        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (grid[row][col] == 1 && !visited[row][col]) {
                    exploreIsLand(grid, row, col, visited);
                    ++isLandCount;
                }
            }
        }

        return isLandCount;
    }

    void exploreIsLand(vector< vector<int> > & grid, int row, int col, vector< vector<bool> > & visited) {
        visited[row][col] = true;

        // check all adjacent cells
        for (const auto & dir : directions) {
            int newRow = row + dir[0];
            int newCol = col + dir[1];

            if (isValidLand(grid, newRow, newCol, visited)) {
                exploreIsLand(grid, newRow, newCol, visited);
            }
        }
    }

    bool isValidLand(vector< vector<int> > & grid, int row, int col, vector< vector<bool> > & visited) {
        // Check bounds, land and not visited
        return row >= 0 && row < rows && col >= 0 && col < cols && grid[row][col] == 1 && !visited[row][col];
    }
};