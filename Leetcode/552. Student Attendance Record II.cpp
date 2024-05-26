class Solution {
    int MOD = 1e9 + 7;
    vector< vector<vector<int>> > dp;
public:
    int checkRecord(int n) {
        vector<vector<int>> row(2, vector<int>(3, -1));
        dp.resize(n + 1, row);

        return solve(n, 0, 0);
    }

    int solve(int n, int totalAbsent, int consecutiveLate) {
        if (totalAbsent >= 2 || consecutiveLate >= 3) {
            return (0);
        }

        if (n == 0) return 1;

        if (dp[n][totalAbsent][consecutiveLate] != -1) return dp[n][totalAbsent][consecutiveLate];

        int count = 0;
        // Present
        count = solve(n - 1, totalAbsent, 0) % MOD;
        // Absent
        count += solve(n - 1, totalAbsent + 1, 0) % MOD;
        count %= MOD;
        // Late
        count += solve(n - 1, totalAbsent, consecutiveLate + 1);

        return dp[n][totalAbsent][consecutiveLate] = count % MOD;
    }
};