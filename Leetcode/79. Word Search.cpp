class Solution {
    int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    vector<vector<bool>> visited;
    int m, n;
public:
    bool exist(vector<vector<char>>& board, string word) {
        int i, j;
        m = board.size();
        n = board[0].size();

        vector<bool> visitedRow(n, false);
        for (i = 0; i < m; ++i) visited.push_back(visitedRow);

        bool ans = false;

        for (i = 0; i < m && !ans; ++i) {
            for (j = 0; j < n && !ans; ++j) {
                if (board[i][j] == word[0]) {
                    ans = isExist(board, word, 0, i, j);
                }
            }
        }

        return ans;
    }

    bool isExist(vector<vector<char>>& board, string& word, int index, int x, int y) {

        if (index >= word.size() || board[x][y] != word[index]) return false;

        if (index == word.size() - 1) {
            return true;
        }

        visited[x][y] = true;

        int i, newX, newY;
        bool ans = false;
        for (i = 0; i < 4 && !ans; ++i) {
            newX = x + dir[i][0];
            newY = y + dir[i][1]; 
            if (isValid(newX, newY)) {
                ans = isExist(board, word, index + 1, newX, newY);
            }
        }

        visited[x][y] = false;

        return ans;
    }

    bool isValid(int x, int y) {
        if (x < 0 || y < 0 || x >= m || y >= n) return false;

        return !visited[x][y];
    }
};