class Solution {
    int ans = 0;
    int n;
public:
    int totalNQueens(int n) {
        this->n = n;
        vector<bool> vRow(9), vColumn(9), vFrontSlash(18), vBackSlash(18);

        solve(0, vRow, vColumn, vFrontSlash, vBackSlash);

        return ans;
    }

    void solve(int row, vector<bool>& vRow, vector<bool>& vColumn, vector<bool>& vFrontSlash, vector<bool>& vBackSlash) {
        if (row >= n) {
            ++ ans;
            return;
        }

        for (int i = 0; i < n; ++i) {
            bool pos = isPossible(row, i, vRow, vColumn, vFrontSlash, vBackSlash);
            vector<bool> visitedC = vColumn;
            if (pos) {
                mark(row, i, true, vRow, vColumn, vFrontSlash, vBackSlash);
                solve(row + 1, vRow, vColumn, vFrontSlash, vBackSlash);
                mark(row, i, false, vRow, vColumn, vFrontSlash, vBackSlash);
            }
        }
    }

    bool isPossible(int x, int y, vector<bool>& vRow, vector<bool>& vColumn, vector<bool>& vFrontSlash, vector<bool>& vBackSlash) {
        if (vRow[x]) return false;
        if (vColumn[y]) return false;
        if (vFrontSlash[x + y]) return false;
        if (vBackSlash[(x - y) + (n - 1)]) return false;

        return true;
    }

    void mark(int x, int y, bool value, vector<bool>& vRow, vector<bool>& vColumn, vector<bool>& vFrontSlash, vector<bool>& vBackSlash) {
        vRow[x] = value;
        vColumn[y] = value;
        vFrontSlash[x + y] = value;
        vBackSlash[(x - y) + (n - 1)] = value;
    }
};