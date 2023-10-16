class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();

        int len = nums.size();

        vector<int> ans;
        for (int i = len - k; i < len; ++i) {
            ans.push_back(nums[i]);
        }

        for (int i = 0; i < len - k; ++i) {
            ans.push_back(nums[i]);
        }

        for (int i = 0; i < len; ++i) {
            nums[i] = ans[i];
        }

    }
};