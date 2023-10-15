class Solution {
    int dp[501][501];
    int len;
    int mod = 1e9 + 7;
public:
    int numWays(int steps, int arrLen) {
        memset(dp, -1, sizeof(dp));
        len = arrLen;
        
        return solve(steps, 0);
    }

    // Index can be max 501
    int solve(int remain, int index) {
        if (index < 0 || index >= len) return (0);

        if (remain == 0) {
            if (index == 0) return 1;
            else return 0;
        }

        if (dp[remain][index] != -1) return dp[remain][index];

        int ans = solve(remain - 1, index) % mod;
        ans += solve(remain - 1, index - 1);
        ans %= mod;

        ans += solve(remain - 1, index + 1);
        ans %= mod;

        return dp[remain][index] = ans;
    }
};