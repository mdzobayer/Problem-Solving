class Solution {
    int n, dp[101][101];
    bool visited[101][101];
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int i;
        int ans = INT_MAX;
        n = matrix.size();

        memset(visited, false, sizeof(visited));

        for (i = 0; i < n; ++i) {
            ans = min(ans, dfs(0, i, matrix));
        }

        return ans;
    }

    int dfs(int x, int y, vector<vector<int>>& matrix) {

        if (x < 0 || x >= n || y < 0 || y >= n) return 0;

        if (visited[x][y]) return dp[x][y];

        int ans = INT_MAX;
        bool isLast = false;

        if (isValid(x + 1, y - 1)) {
            isLast = true;
            ans = min(ans, dfs(x + 1, y - 1, matrix));
        }

        if (isValid(x + 1, y)) {
            isLast = true;
            ans = min(ans, dfs(x + 1, y, matrix));
        }

        if (isValid(x + 1, y + 1)) {
            isLast = true;
            ans = min(ans, dfs(x + 1, y + 1, matrix));
        }

        if (!isLast) {
            ans = matrix[x][y];
        }
        else {
            ans += matrix[x][y];
        }

        visited[x][y] = true;
        return dp[x][y] = ans;
    }

    bool isValid(int x, int y) {
        if (x < 0 || x >= n || y < 0 || y >= n) return false;
        return true;
    }
};