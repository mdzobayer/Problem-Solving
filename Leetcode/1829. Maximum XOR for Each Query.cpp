class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int i, n = nums.size();

        vector<int> prefixXOR(n), ans(n);
        prefixXOR[0] = nums[0];

        for (i = 1; i < n; ++i) {
            prefixXOR[i] = prefixXOR[i - 1] ^ nums[i];
        }

        int mask = (1 << maximumBit) - 1;

        for (i = 0; i < n; ++i) {
            ans[i] = prefixXOR[n - 1 - i] ^ mask;
        }

        return ans;
    }
};