class Solution {
    int mod = 1e9 + 7;
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high + 1);
        dp[0] = 1;
        int end, i, ans = 0;

        for (end = 1; end <= high; ++end) {
            if (end >= zero) {
                dp[end] += dp[end - zero];
            }
            if (end >= one) {
                dp[end] += dp[end - one];
            }
            dp[end] %= mod;
        }

        for (i = low; i <= high; ++i) {
            ans += dp[i];
            ans %= mod;
        }

        return ans;
    }
};