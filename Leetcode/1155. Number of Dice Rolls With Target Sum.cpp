class Solution {
    int target, k;
    int mod = 1e9 + 7;
    int dp[31][1001];
public:
    int numRollsToTarget(int n, int k, int target) {
        this->target = target;
        this->k = k;

        memset(dp, -1, sizeof(dp));

        return solve(n, 0);
    }

    int solve(int n, int sum) {
        if (n == 0 && sum == target) return 1;
        if (n == 0 || sum > target) return 0;

        if (dp[n][sum] != -1) return dp[n][sum];

        int i, ans = 0;
        for (i = 1; i <= k; ++i) {
            ans += solve(n - 1, sum + i);
            ans %= mod;
        }

        return dp[n][sum] = ans;
    }
};