class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        vector<int> prefixSum(arr.begin(), arr.end());
        int i, j, sum = 0, n = arr.size();

        for (i = 1; i < n; ++i) {
            prefixSum[i] += prefixSum[i - 1];
        }

        for (i = 1; i <= n; i += 2) {
            for (j = i - 1; j < n; ++j) {
                sum += prefixSum[j];
                if (j - i >= 0) sum -= prefixSum[j - i];
            }
        }

        return sum;
    }
};