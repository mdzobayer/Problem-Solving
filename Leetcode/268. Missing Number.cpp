class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i, ans = 0, n = nums.size();
        vector<bool> available(10001, false);

        for (i = 0; i < n; ++i) {
            available[nums[i]] = true;
        }

        for (i = 0; i < 10001; ++i) {
            if (!available[i]) {
                ans = i;
                break;
            }
        }

        return ans;
    }
};