class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i, ans = -1, n = nums.size();
        vector<bool> isDuble(n + 1, false);

        for (i = 0; i < n; ++i) {
            if (isDuble[nums[i]]) {
                ans = nums[i];
                break;
            }

            isDuble[nums[i]] = true;
        }

        return ans;
    }
};