class Solution {
    int mod = 1e9 + 7;
    vector<vector<int>> knightMoves = {{4,6},{6,8},{7,9},{4,8},{0,3,9},{},{0,1,7},{2,6},{1,3},{2,4}};
    int dp[5001][10];
public:
    int knightDialer(int n) {
        memset(dp, -1, sizeof(dp));

        int ans = 0;
        for (int digit = 0; digit < 10; ++digit) {
            ans += (solve(n, digit)) % mod;
            ans %= mod;
        }

        return ans;
    }

    int solve(int n, int digit) {
        if (n == 1) return 1;

        if (dp[n][digit] != -1) return dp[n][digit];

        int ans = 0;
        for (int i = 0; i < knightMoves[digit].size(); ++i) {
            ans += (solve(n - 1, knightMoves[digit][i])) % mod;
            ans %= mod;
        }

        return dp[n][digit] = ans;
    }
};