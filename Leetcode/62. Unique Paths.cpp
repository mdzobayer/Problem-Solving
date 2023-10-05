class Solution {
    int row, column;
    vector<vector<int>> dp;
public:
    int uniquePaths(int m, int n) {
        row = m;
        column = n;
        dp.clear();
        vector<int> aRow;

        for (int i = 0; i < column; ++i) {
            aRow.push_back(-1);
        }

        for (int i = 0; i < row; ++i) {
            dp.push_back(aRow);
        }

        return findPath(0, 0);
    }

    int findPath(int x, int y) {
        if (x >= row || y >= column) return (0);

        if (x == row - 1 || y == column - 1) return 1;

        if(dp[x][y] != -1) return dp[x][y];

        return dp[x][y] = findPath(x + 1, y) + findPath(x, y + 1);
    }
};