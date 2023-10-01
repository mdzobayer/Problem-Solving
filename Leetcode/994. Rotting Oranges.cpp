class Solution {
public:

    int direactionArray[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    struct Cell {
        int row, column, level;
    };

    int orangesRotting(vector<vector<int>>& grid) {
        int i, j, m, n, ans = 0, freshOranges = 0;
        m = grid.size();
        n = grid[0].size();

        vector<bool> visited;
        vector<vector<bool>> visitedGrid;

        Cell rottenCell{0, 0, 0};

        queue<Cell> q;

        // prepare visited grid
        for (i = 0; i < m; ++i) {
            visitedGrid.push_back(visited);
            for (j = 0; j < n; ++j) {
                visitedGrid[i].push_back(false);
                if (grid[i][j] == 1) {
                    ++ freshOranges;
                }
                else if (grid[i][j] == 2) {
                    rottenCell.row = i;
                    rottenCell.column = j;

                    q.push(rottenCell);
                    markVisited(visitedGrid, rottenCell);
                }
            }
        }

        while(!q.empty()) {
            rottenCell = q.front();
            q.pop();

            ans = max(rottenCell.level, ans);

            for (i = 0; i < 4; ++i) {
                Cell newCell{rottenCell.row + direactionArray[i][0], rottenCell.column + direactionArray[i][1], rottenCell.level + 1};

                if (isPossibleToMove(m, n, visitedGrid, grid, newCell)) {
                    q.push(newCell);
                    markVisited(visitedGrid, newCell);
                    --freshOranges;
                }
            }
        }

        if (freshOranges > 0) ans = -1;

        return ans;
    }

    void markVisited(vector<vector<bool>> & visitedGrid, Cell cell) {
        visitedGrid[cell.row][cell.column] = true;
    }

    bool isPossibleToMove(int m, int n, vector<vector<bool>> & visitedGrid, vector<vector<int>>& grid, Cell cell) {

        if (cell.row < 0 || cell.column < 0 || cell.row > m - 1 || cell.column > n - 1) return false;

        if (visitedGrid[cell.row][cell.column]) return false;

        if (grid[cell.row][cell.column] != 1) return false;

        return true;
    }
};