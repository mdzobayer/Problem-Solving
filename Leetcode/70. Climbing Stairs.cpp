class Solution {
    int dp[50];
    bool reset = true;
public:
    int climbStairs(int n) {
        if (n == 0) return 1;
        if (n < 0) return 0;

        if (reset) {
            memset(dp, -1, sizeof(dp));
            reset = false;
        }

        if (dp[n] != -1) return dp[n];

        return dp[n] = climbStairs(n - 1) + climbStairs(n - 2);
    }
};