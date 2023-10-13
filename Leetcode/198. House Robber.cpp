class Solution {
    int dp[105];
public:
    int rob(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));

        int ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            ans = max(ans, solve(i, nums));
        }

        return ans;
    }

    int solve(int index, vector<int>& nums) {
        if (index >= nums.size()) return (0);

        if (dp[index] != -1) return dp[index];
        int ans = 0;
        for (int i = 2; i < nums.size(); ++i) {
            ans = max(ans, solve(index + i, nums));
        }

        return dp[index] = ans + nums[index];
    }
};