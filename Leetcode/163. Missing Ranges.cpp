class Solution {
public:
    vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<vector<int>> ans;
        int i;

        if (nums.size() == 0) {
            ans.push_back(vector<int>{lower, upper});
            return ans;
        }

        if (lower < nums.front()) {
            ans.push_back(vector<int>{lower, nums[i] - 1});
        }

        for (i = 1; i < nums.size(); ++i) {
            if (nums[i] - nums[i - 1] > 1) {
                ans.push_back(vector<int>{nums[i - 1] + 1, nums[i] - 1});
            }
        }

        if (nums.back() < upper) {
            ans.push_back(vector<int>{nums.back() + 1, upper});
        }

        return ans;
    }
};