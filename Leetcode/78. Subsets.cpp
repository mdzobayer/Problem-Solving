class Solution {
    vector< vector<int> > ans;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset;
        generateSubset(nums, subset, 0);

        return ans;
    }

    void generateSubset(vector<int> & nums, vector<int> subset, int index) {
        ans.push_back(subset);

        if (index == nums.size()) return;

        for (int i = index; i < nums.size(); ++i) {
            subset.push_back(nums[i]);
            generateSubset(nums, subset, i + 1);
            subset.pop_back();
        }
    }
};