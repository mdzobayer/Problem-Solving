class Solution {
    int dp[2500 + 5];
public:
    int lengthOfLIS(vector<int>& nums) {
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
        for (int i = index + 1; i < nums.size(); ++i) {
            if (nums[i] > nums[index]) {
                ans = max(ans, solve(i, nums));
            }
        }

        return dp[index] = ans + 1;
    }
};