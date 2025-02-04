class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxSum = 0, current, i, n = nums.size();
        current = nums[0];

        for (i = 1; i < n; ++i) {
            if (nums[i] > nums[i - 1]) {
                current += nums[i];
            }
            else {
                maxSum = max(maxSum, current);
                current = nums[i];
            }
        }

        maxSum = max(maxSum, current);

        return maxSum;
    }
};