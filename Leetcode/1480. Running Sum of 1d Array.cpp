class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int i, n = nums.size();

        vector<int> ans(nums.begin(), nums.end());
        for (i = 1; i < n; ++i) {
            ans[i] += ans[i - 1];
        }

        return ans;
    }
};