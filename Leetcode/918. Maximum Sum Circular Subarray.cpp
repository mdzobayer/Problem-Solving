class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int i, j, n = nums.size();
        int currentSum = 0, maxSoFar = INT_MIN;

        for(i = 0; i < n; ++i) {
            currentSum += nums[i];
            maxSoFar = max(maxSoFar, currentSum);
            currentSum = max(currentSum, 0);
        }

        vector<int> rightMax(n, 0), suffixSum(n, 0);
        rightMax[n - 1] = nums[n - 1];
        suffixSum[n - 1] = nums[n - 1];

        for (i = n - 2; i >= 0; --i) {
            suffixSum[i] = nums[i] + suffixSum[i + 1];
            rightMax[i] = max(rightMax[i + 1], suffixSum[i]);
        }

        int prefixSum = 0, specialSum = INT_MIN;
        for (i = 0; i < n - 1; ++i) {
            prefixSum += nums[i];
            specialSum = max(specialSum, prefixSum + rightMax[i + 1]);
        }

        return max(maxSoFar, specialSum);
    }
};