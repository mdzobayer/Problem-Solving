class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int i, j, ans, n = prices.size();

        if (k / 2 > n) {
            ans = 0;
            for (i = 1; i < n; ++i) {
                ans += max(0, prices[i] - prices[i - 1]);
            }
        }

        int dp[n][k + 1][2];
        // initialize the array with -inf
        // we use -1e9 here to prevent overflow
        for (i = 0; i < n; i++) {
            for (j = 0; j <= k; j++) {
                dp[i][j][0] = -1000000000;
                dp[i][j][1] = -1000000000;
            }
        }

        dp[0][0][0] = 0;
        dp[0][1][1] = -prices[0];

        for (i = 1; i < n; ++i) {
            for (j = 0; j <= k; ++j) {
                // Buying ith stock
                if (j > 0)
                    dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i]);

                // selling ith stock
                dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i]);
            }
        }

        ans = 0;
        for (j = 0; j <= k; ++j) {
            ans = max(ans, dp[n - 1][j][0]);
        }

        return ans;
    }
};