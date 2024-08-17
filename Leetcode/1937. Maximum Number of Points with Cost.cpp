class Solution {
    int m, n;
    vector< vector<int> > dp;
public:
    long long maxPoints(vector<vector<int>>& points) {
        m = points.size();
        n = points[0].size();
        dp.resize(m, vector<int>(n, -1));

        long long ans = 0;

        // for (int i = 0; i < n; ++i) {
        //     ans = max(ans, solve(points, 0, i));
        // }

        vector<long long> previousRow(n);
        int row, col;
        for (col = 0; col < n; ++col) {
            previousRow[col] = points[0][col];
        }

        for (row = 0; row < m - 1; ++row) {
            vector<long long> leftMax(n), rightMax(n), currentRow(n);

            leftMax[0] = previousRow[0];
            for (col = 1; col < n; ++col) {
                leftMax[col] = max(leftMax[col - 1] - 1, previousRow[col]);
            }

            rightMax[n - 1] = previousRow[n - 1];
            for (col = n - 2; col >= 0; --col) {
                rightMax[col] = max(rightMax[col + 1] - 1, previousRow[col]);
            }

            for (col = 0; col < n; ++col) {
                currentRow[col] = points[row + 1][col] + max(leftMax[col], rightMax[col]);
            }

            previousRow = currentRow;
        }

        for (col = 0; col < n; ++col) {
            ans = max(ans, previousRow[col]);
        }

        return ans;
    }

    // long long solve(vector<vector<int>>& points, int x, int y) {
    //     if (x == m) return 0;

    //     if (dp[x][y] != -1) return dp[x][y];

    //     long long ans = 0;
    //     for (int i = 0; i < n && (x + 1) < m; ++i){
    //         ans = max(ans, (long long)solve(points, x + 1, i) - abs(y - i));
    //     }

    //     ans += points[x][y];

    //     return dp[x][y] = ans;
    // }
};