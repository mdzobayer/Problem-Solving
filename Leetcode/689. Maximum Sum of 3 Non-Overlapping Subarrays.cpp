class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int i, windowSum = 0, n = nums.size() - k + 1;

        vector<int> sums(n);
        for (i = 0; i < k; ++i) {
            windowSum += nums[i];
        }
        sums[0] = windowSum;

        for (i = k; i < nums.size(); ++i) {
            windowSum = windowSum - nums[i - k] + nums[i];
            sums[i - k + 1] = windowSum;
        }

        vector<vector<int>> dp(n, vector<int>(4, -1));
        vector<int> indices;

        solve(sums, k, 0, 3, dp);
        dfs(sums, k, 0, 3, dp, indices);
        
        return indices;
    }

    int solve(vector<int>& sums, int k, int idx, int rem, vector<vector<int>>& dp) {
        if (rem == 0) return 0;
        if (idx >= sums.size()) {
            return rem > 0 ? INT_MIN : 0;
        }

        if (dp[idx][rem] != -1) {
            return dp[idx][rem];
        }

        int withCurrent = sums[idx] + solve(sums, k, idx + k, rem - 1, dp);
        int skipCurrent = solve(sums, k, idx + 1, rem, dp);

        return dp[idx][rem] = max(withCurrent, skipCurrent);
    }

    void dfs(vector<int>& sums, int k, int idx, int rem, vector<vector<int>>& dp, vector<int>& indices) {
        if (rem == 0) return;
        if (idx >= sums.size()) return;

        int withCurrent = sums[idx] + solve(sums, k, idx + k, rem - 1, dp);
        int skipCurrent = solve(sums, k, idx + 1, rem, dp);

        if (withCurrent >= skipCurrent) {
            indices.push_back(idx);
            dfs(sums, k, idx + k, rem - 1, dp, indices);
        }
        else {
            dfs(sums, k, idx + 1, rem, dp, indices);
        }
    }
};