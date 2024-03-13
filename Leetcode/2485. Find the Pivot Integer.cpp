class Solution {
public:
    int pivotInteger(int n) {
        int i, ans = -1;
        vector<int> prefixSum(n + 1, 0), suffixSum(n + 2, 0);

        for (i = 1; i <= n; ++i) {
            prefixSum[i] = prefixSum[i - 1] + i;
        }

        for (i = n; i > 0; --i) {
            suffixSum[i] = suffixSum[i + 1] + i;
        }

        for (i = 1; i <= n; ++i) {
            if (suffixSum[i] == prefixSum[i]) {
                ans = i;
                break;
            }
        }

        return ans;
    }
};