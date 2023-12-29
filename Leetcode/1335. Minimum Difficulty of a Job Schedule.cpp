class Solution {
    int n;
    int dp[301][11];
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        if (jobDifficulty.size() < d) return -1;

        n = jobDifficulty.size();
        memset(dp, -1, sizeof(dp));

        return solve(0, d, jobDifficulty);
    }

    int solve(int index, int d, vector<int>& jobDifficulty) {
        if (index < n && d == 0) return INT_MAX;
        if (index == n) return 0;

        if (dp[index][d] != -1) return dp[index][d];

        int i, tempResult, ans = INT_MAX, maximumEle = jobDifficulty[index];
        for (i = index; i <= (n - d); ++i) {
            maximumEle = max(maximumEle, jobDifficulty[i]);

            tempResult = solve(i + 1, d - 1, jobDifficulty);
            if (tempResult != INT_MAX) {
                tempResult += maximumEle;
            }
            ans = min(ans, tempResult);
        }

        return dp[index][d] = ans;
    }
};