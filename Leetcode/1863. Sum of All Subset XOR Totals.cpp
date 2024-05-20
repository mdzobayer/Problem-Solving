class Solution {
    int ans = 0;
public:
    int subsetXORSum(vector<int>& nums) {
        vector<int> subset;

        backtrack(nums, subset, 0);

        return ans;
    }

    void backtrack(vector<int>& nums, vector<int>& subset, int index) {

        int i, data;
        if (subset.size() > 0) {
            for (i = 0; i < subset.size(); ++i) {
                if (i > 0) {
                    data ^= subset[i];
                }
                else data = subset[i];
            }
            ans += data;
        }

        if (index == nums.size()) return;

        for (i = index; i < nums.size(); ++i) {
            subset.push_back(nums[i]);
            backtrack(nums, subset, i + 1);
            subset.pop_back();
        }
    }
};