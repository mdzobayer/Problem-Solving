class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int i, max_val = 0, ans = 0, n = nums.size();

        for (int val : nums) {
            max_val = max(max_val, val);
        }

        vector<int> freq(n + max_val + 1, 0);

        for (i = 0; i < n; ++i) {
            ++ freq[nums[i]];
        }

        for (i = 0; i <= n + max_val; ++i) {
            if (freq[i] > 1) {
                ans += freq[i] - 1;
                freq[i + 1] += freq[i] - 1;
                freq[i] = 1;
            }
        }

        return ans;
    }
};