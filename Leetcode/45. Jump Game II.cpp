class Solution {
    int dp[10001];
    int n;
public:
    int jump(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        n = nums.size();

        return solve(0, nums);
    }

    int solve(int index, vector<int>& nums) {
        if (index >= n) {
            return INT_MAX;
        }

        if (index == n - 1) return 0;

        if (dp[index] != -1) return dp[index];

        int ans = INT_MAX;
        for (int i = 1; i <= nums[index]; ++i) {
            int cAns = solve(index + i, nums);
            if (cAns < INT_MAX) ++ cAns;
            ans = min(ans, cAns);
        }

        return dp[index] = ans;
    }
};