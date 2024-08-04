class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int i = 0, n = nums.size();
        vector<int> ans(n);

        for (int item : nums) {
            ans[i++] = nums[item];
        }

        return ans;
    }
};