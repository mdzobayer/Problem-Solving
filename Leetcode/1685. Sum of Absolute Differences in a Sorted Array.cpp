class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int i, leftDiff, rightDiff, sum, n = nums.size();
        vector<int> ans(n, 0), prefixSum(n, 0);

        prefixSum[0] = nums[0];
        for (i = 1; i < nums.size(); ++i) {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }

        for (i = 0; i < n; ++i) {
            leftDiff = 0;
            rightDiff = 0;

            if (i > 0) {
                leftDiff = (nums[i] * i) - prefixSum[i - 1];
            }
            if (i < n - 1) {
                rightDiff = (prefixSum[n - 1] - prefixSum[i]) - (nums[i] * (n - i - 1));
            }

            ans[i] = leftDiff + rightDiff;
        }

        return ans;
    }
};