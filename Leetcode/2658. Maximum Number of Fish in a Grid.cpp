class Solution {
    vector<vector<int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size(), ans = 0;

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] > 0 && !visited[i][j]) {
                    ans = max(ans, calculate(grid, visited, i, j));
                }
            }
        }

        return ans;
    }

    int calculate(vector<vector<int>>& grid, vector<vector<bool>>& visited, int row, int col) {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == 0 || visited[row][col]) {
            return 0;
        }

        visited[row][col] = true;

        int ans = grid[row][col];

        for (auto dir : dirs) {
            ans += calculate(grid, visited, row + dir[0], col + dir[1]);
        }

        return ans;
    }
};