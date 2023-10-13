class Solution {
    struct Cell {
        int row, column, level, direction;
        //vector<pair<int,int>> path;
        void setValue(int xx, int yy, int le, int dir) {
            row = xx; column = yy; level = le; direction = dir;
        }
    };

    int n, m;
    bool visited[100][100][4];
    int directionArray[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        n = maze.size(), m = maze[0].size();
        memset(visited, false, sizeof(visited));

        queue<Cell> qu;

        Cell frontCell;
        frontCell.setValue(start[0] - 1,start[1], 1, 0);
        if (isValid(frontCell, maze)) {
            visited[frontCell.row][frontCell.column][frontCell.direction] = true;
            qu.push(frontCell);
        }
        

        frontCell.setValue(start[0],start[1] - 1, 1, 1);
        if (isValid(frontCell, maze)) {
            visited[frontCell.row][frontCell.column][frontCell.direction] = true;
            qu.push(frontCell);
        }

        frontCell.setValue(start[0] + 1,start[1], 1, 2);
        if (isValid(frontCell, maze)) {
            visited[frontCell.row][frontCell.column][frontCell.direction] = true;
            qu.push(frontCell);
        }

        frontCell.setValue(start[0],start[1] + 1, 1, 3);
        if (isValid(frontCell, maze)) {
            visited[frontCell.row][frontCell.column][frontCell.direction] = true;
            qu.push(frontCell);
        }

        while(!qu.empty()) {
            frontCell = qu.front();
            qu.pop();

            // check with destination
            Cell move = newMoveOnOldDirection(frontCell);

            if (isValid(move, maze)) {
                visited[move.row][move.column][move.direction] = true;
                qu.push(move);
            }
            else {
                if (frontCell.row == destination[0] && 
                    frontCell.column == destination[1]) {
                    return frontCell.level;
                }

                Cell newMove;
                for (int i = 0; i < 4; ++i) {
                    newMove.setValue(frontCell.row + directionArray[i][0],
                    frontCell.column + directionArray[i][1],
                    frontCell.level + 1, i);
                    

                    if (isValid(newMove, maze)) {
                        visited[newMove.row][newMove.column][newMove.direction] = true;
                        qu.push(newMove);
                    }
                }
            }
        }

        return -1;
    }

    bool isValid(Cell cell, vector<vector<int>>& maze) {
        if (cell.row < 0 || cell.column < 0) return false;
        if (cell.row >= n || cell.column >= m) return false;

        if(maze[cell.row][cell.column] == 1) return false;

        if(visited[cell.row][cell.column][cell.direction]) return false;

        return true;
    }

    Cell newMoveOnOldDirection(Cell previous) {
        Cell cell = previous;
        if (cell.direction == 0) {
            cell.row += -1;
        }
        else if (cell.direction == 1) {
            cell.column += -1;
        }
        else if (cell.direction == 2) {
            cell.row += 1;
        }
        else if (cell.direction == 3) {
            cell.column += 1;
        }

        cell.level += 1;

        return cell;
    }
};