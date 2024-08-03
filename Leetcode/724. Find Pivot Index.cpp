class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int i, n = nums.size();

        if (n == 1) return 0;

        vector<int> prefixSum(n, 0), suffixSum(n, 0);

        for (i = 0; i < n; ++i) {
            prefixSum[i] = nums[i];
            if (i > 0) {
                prefixSum[i] += prefixSum[i - 1];
            }
            
            suffixSum[n - i - 1] = nums[n - i - 1];
            if (n - i - 1 < n - 1) {
                 suffixSum[n - i - 1] +=  suffixSum[n - i];
            }
        }

        if (suffixSum[1] == 0) return 0;

        for (i = 1; i < n - 1; ++i) {
            if (prefixSum[i - 1] == suffixSum[i + 1]) {
                return i;
            }
        }

        if (prefixSum[n - 2] == 0) return n - 1;

        return -1;
    }
};