class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n + 1, 1000);
        dp[1] = 0;

        int i, j;
        for (i = 2; i <= n; ++i) {
            for (j = 1; j <= i/2; ++j) {
                if (i % j == 0)
                    dp[i] = min(dp[i], dp[j] + i / j);
            }
        }

        return dp[n];
    }
};