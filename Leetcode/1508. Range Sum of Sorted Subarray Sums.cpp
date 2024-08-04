class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int i, j, k = 0;
        int mod = 1e9 + 7;

        vector<int> prefixSum(n, 0), numbers((n * (n + 1)) / 2);
        prefixSum[0] = nums[0];

        for (i = 1; i < n; ++i) prefixSum[i] += nums[i] + prefixSum[i - 1];

        for (i = 0; i < n; ++i) {
            for (j = i; j < n; ++j) {
                int sum = prefixSum[j];
                if (i > 0) sum -= prefixSum[i - 1];
                numbers[k++] = sum;
            }
        }

        sort(numbers.begin(), numbers.end());

        int ans = 0;

        for (i = left - 1; i < right; ++i) {
            ans += numbers[i];
            ans %= mod;
        }

        return ans;
    }
};