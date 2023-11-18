class Solution {
    bool visited[205][205];
    int dir4[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int m, n;
public:
    void solve(vector<vector<char>>& board) {
        memset(visited, false, sizeof(visited));
        m = board.size();
        n = board[0].size();

        int i, j;
        pair<int,int> coordinate;
        for (i = 0; i < m; ++i) {
            for (j = 0; j < n; ++j) {
                if (board[i][j] == 'O' && !visited[i][j]) {
                    coordinate = make_pair(i, j);
                    bool isSide = checkRegion(coordinate, board);
                    if (!isSide) {
                        markRegion(coordinate, board);
                    }
                }
            }
        }
    }

    bool checkRegion(const pair<int,int>& coordinate, vector<vector<char>>& board) {
        visited[coordinate.first][coordinate.second] = true;

        bool isSideRegion = false;

        pair<int, int> newCoordinate;
        for (int i = 0; i < 4; ++i) {
            newCoordinate.first = coordinate.first + dir4[i][0];
            newCoordinate.second = coordinate.second + dir4[i][1];

            if(!isValid(newCoordinate)) {
                isSideRegion = true;
                continue;
            }

            if (board[newCoordinate.first][newCoordinate.second] == 'O' && 
            !visited[newCoordinate.first][newCoordinate.second]) {
                bool otherRegionAns = checkRegion(newCoordinate, board);
                isSideRegion = isSideRegion ? isSideRegion : otherRegionAns;
            }
        }

        return isSideRegion;
    }

    void markRegion(const pair<int,int>& coordinate, vector<vector<char>>& board) {

        board[coordinate.first][coordinate.second] = 'X';

        pair<int, int> newCoordinate;
        for (int i = 0; i < 4; ++i) {
            newCoordinate.first = coordinate.first + dir4[i][0];
            newCoordinate.second = coordinate.second + dir4[i][1];

            if(!isValid(newCoordinate)) {
                continue;
            }

            if (board[newCoordinate.first][newCoordinate.second] == 'O') {
                markRegion(newCoordinate, board);
            }
        }

    }

    bool isValid(const pair<int,int>& coordinate) {
        if (coordinate.first < 0 || coordinate.second < 0 || 
            coordinate.first >= m || coordinate.second >= n) return false;

        return true;
    }
};