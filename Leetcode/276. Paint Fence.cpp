class Solution {
    vector<int> dp;
public:
    int numWays(int n, int k) {
        dp.resize(n + 1, -1);

        return solve(n, k);
    }

    int solve(int n, int k) {
        if (n == 1) return k;
        else if (n == 2) return k * k;

        if (dp[n] != -1) {
            return dp[n];
        }

        return dp[n] = (k - 1) * (solve(n - 1, k) + solve(n - 2, k));
    }
};