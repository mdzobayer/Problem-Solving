class Solution {
public:

    int directionArray[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    struct Cell {
        int row, column, level;
    };

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        
        int i, j, ans = -1, m, n;
        vector<bool> visited;
        vector<vector<bool>> visitedMaze;

        // prepare visitedMaze
        m = maze.size();
        for (i = 0; i < m; ++i) {
            visitedMaze.push_back(visited);
            n = maze[i].size();
            for (j = 0; j < n; ++j) {
                visitedMaze[i].push_back(false);
            }
        }

        Cell cell{entrance[0], entrance[1], 0};

        queue<Cell> q;
        q.push(cell);
        markVisited(visitedMaze, cell);

        while(!q.empty()) {

            cell = q.front();
            q.pop();

            for (i = 0; i < 4; ++i) {
                Cell newCell{cell.row + directionArray[i][0], cell.column + directionArray[i][1], cell.level + 1};

                if (isPossibleToMove(m, n, maze, visitedMaze, newCell)) {
                    if (newCell.row == 0 || newCell.column == 0 || newCell.row == m - 1 || newCell.column == n - 1){
                       return newCell.level; 
                    } 

                    markVisited(visitedMaze, newCell);
                    q.push(newCell);
                }

            }
        }

        return ans;
    }

    bool isPossibleToMove(int m, int n, vector<vector<char>>& maze, vector<vector<bool>>& visitedMaze, Cell cell) {

        if (cell.row < 0 || cell.column < 0 || cell.row > m -1 || cell.column > n - 1) {
            return false;
        }

        if (maze[cell.row][cell.column] != '.') return false;

        if (visitedMaze[cell.row][cell.column]) return false;

        return true;
    }

    void markVisited(vector<vector<bool>>& visitedMaze, Cell & cell) {
        visitedMaze[cell.row][cell.column] = true;
    }
};