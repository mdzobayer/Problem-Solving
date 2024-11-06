class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int i, j, n = nums.size();

        vector<int> values(nums.begin(), nums.end());

        for (i = 0; i < n; ++i) {
            for (j = 0; j < n - i - 1; ++j) {
                if (values[j] <= values[j + 1]) {
                    // No swap needed
                    continue;
                }
                else {
                    if (__builtin_popcount(nums[j]) == __builtin_popcount(nums[j + 1])) {
                        swap(values[j], values[j + 1]);
                    }
                    else {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};