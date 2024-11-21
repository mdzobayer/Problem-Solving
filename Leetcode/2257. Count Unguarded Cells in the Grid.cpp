class Solution {
public:
    const int unGuarded = 0, guarded = 1, guard = 2, wall = 3;

    void markGuarded(int row, int col, vector< vector<int> >& grid) {
        // upwards
        for (int r = row - 1; r >= 0; --r) {
            if (grid[r][col] == wall || grid[r][col] == guard) break;
            grid[r][col] = guarded;
        }

        // downwards
        for (int r = row + 1; r < grid.size(); ++r) {
            if (grid[r][col] == wall || grid[r][col] == guard) break;
            grid[r][col] = guarded;
        }

        // rightwards
        for (int c = col - 1; c >= 0; --c) {
            if (grid[row][c] == wall || grid[row][c] == guard) break;
            grid[row][c] = guarded;
        }

        // leftwards
        for (int c = col + 1; c < grid[row].size(); ++c) {
            if (grid[row][c] == wall || grid[row][c] == guard) break;
            grid[row][c] = guarded;
        }
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector< vector<int> > grid(m, vector<int>(n, unGuarded));

        // Mark guards
        for (const auto& aGuard : guards) {
            grid[aGuard[0]][aGuard[1]] = guard;
        }

        // Mark walls
        for (const auto& aWall : walls) {
            grid[aWall[0]][aWall[1]] = wall;
        }

        for (const auto& aGuard : guards) {
            markGuarded(aGuard[0], aGuard[1], grid);
        }

        int ans = 0;
        for (const auto& row : grid) {
            for (const auto& cell : row) {
                if (cell == unGuarded) ++ ans;
            }
        }

        return ans;
    }
};