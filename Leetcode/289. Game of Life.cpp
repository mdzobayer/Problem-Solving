class Solution {
    int m, n;
    int dir[8][2] = {
        {-1, 0}, {0, 1}, {1, 0}, {0, -1},
        {-1, -1}, {1, 1}, {-1, 1}, {1, -1}
    };

public:
    void gameOfLife(vector<vector<int>>& board) {
        int i, j, liveCell;
        m = board.size();
        n = board[0].size();

        vector<vector<int>> nextRound;
        vector<int> nextRoundRow(n, 0);
        for (i = 0; i < m; ++i) nextRound.push_back(nextRoundRow);

        for (i = 0; i < m; ++i) {
            for (j = 0; j < n; ++j) {
                if (board[i][j] == 0) {
                    liveCell = liveCellCount(board, make_pair(i, j));
                    if (liveCell == 3) {
                        nextRound[i][j] = 1;
                    }
                }
                else {
                    liveCell = liveCellCount(board, make_pair(i, j));
                    if (liveCell < 2 || liveCell > 3) {
                        nextRound[i][j] = 0;
                    }
                    else nextRound[i][j] = 1;
                }
            }
        }

        for (i = 0; i < m; ++i) {
            for (j = 0; j < n; ++j) {
                board[i][j] = nextRound[i][j]; 
            }
        }
    }

    int liveCellCount(vector<vector<int>>& board, const pair<int, int>& position) {
        int count = 0;
        for (int i = 0; i < 8; ++i) {
            pair<int, int> newPosition = make_pair(position.first + dir[i][0],
                position.second + dir[i][1]);
            
            if (isValid(newPosition)) {
                if (board[newPosition.first][newPosition.second] == 1)
                    ++ count;
            }
        }

        return count;
    }

    bool isValid(const pair<int, int>& position) {
        if (position.first < 0 || position.first >= m || 
            position.second < 0 || position.second >= n) return false;

        return true;
    }
};