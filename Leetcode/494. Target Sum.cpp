class Solution {
    int totalSum;
    vector< vector<int> > dp;
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        totalSum = accumulate(nums.begin(), nums.end(), 0);

        dp.resize(nums.size(), vector<int>(2 * totalSum + 1, INT_MIN));
        return solve(nums, 0, 0, target); 
    }

    int solve(vector<int>&nums, int index, int sum, int target) {
        if (index == nums.size()) {
            if (sum == target) {
                return 1;
            }
            return 0;
        }

        if (dp[index][sum + totalSum] != INT_MIN) {
            return dp[index][sum + totalSum];
        }

        int add = solve(nums, index + 1, sum + nums[index], target);
        int subtract = solve(nums, index + 1, sum - nums[index], target);

        return dp[index][sum + totalSum] = add + subtract;
    }
};