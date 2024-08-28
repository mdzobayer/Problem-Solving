class Solution {
    vector< vector<int> > dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int totalRows, totalCols;

    bool isCellLand(int x, int y, const vector<vector<int>>& grid) {
        return grid[x][y] == 1;
    }

    bool isSubIsland(int x, int y, const vector<vector<int>>& grid1, const vector<vector<int>>& grid2, vector<vector<bool>>& visited) {
        bool isSubIsLand = true;

        if (!isCellLand(x, y, grid1)) {
            isSubIsLand = false;
        }

        for (auto & dir : dirs) {
            int nextX = x + dir[0];
            int nextY = y + dir[1];

            if (nextX >= 0 && nextY >= 0 && nextX < totalRows && nextY < totalCols && !visited[nextX][nextY] && isCellLand(nextX, nextY, grid2)) {
                visited[nextX][nextY] = true;

                bool nextCellPartOfSubIsland = isSubIsland(nextX, nextY, grid1, grid2, visited);
                isSubIsLand = isSubIsLand && nextCellPartOfSubIsland;
            }
        }

        return isSubIsLand;
    }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        totalRows = grid2.size();
        totalCols = grid2[0].size();

        vector< vector<bool> > visited(totalRows, vector<bool>(totalCols, false));
        int subIsLandCounts = 0;

        for (int x = 0; x < totalRows; ++x) {
            for (int y = 0; y < totalCols; ++y) {
                if (!visited[x][y] && isCellLand(x, y, grid2)) {
                    visited[x][y] = true;
                    if (isSubIsland(x, y, grid1, grid2, visited)) {
                        ++ subIsLandCounts;
                    }
                }
            }
        }

        return subIsLandCounts;
    }
};