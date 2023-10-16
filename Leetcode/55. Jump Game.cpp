class Solution {
    int dp[10001];
    int n;
public:
    bool canJump(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        n = nums.size();

        return solve(0, nums);
    }

    bool solve(int index, vector<int>& nums) {
        if (index >= n) {
            return false;
        }

        if (index == n - 1) return true;

        if (dp[index] != -1) return (bool) dp[index];

        bool ans = false;
        for (int i = 1; i <= nums[index]; ++i) {
            ans = solve(index + i, nums);
            if (ans) break;
        }

        return dp[index] = (int) ans;
    }
};