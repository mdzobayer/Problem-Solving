class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int i, numberGap, n = nums.size();
        
        for (i = 1; i < n; ++i) {
            numberGap = nums[i] - nums[i - 1] - 1;
            if (numberGap >= k) {
                return nums[i - 1] + k;
            }

            k -= numberGap;
        }

        return nums[n - 1] + k;
    }
};