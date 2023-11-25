class Solution {
    vector<vector<int>> ans;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();

        permutation(0, n - 1, nums);

        return ans;
    }

    void permutation(int startIndex, int endIndex, vector<int>& nums) {
        if (startIndex == endIndex) {
            ans.push_back(nums);
            return;
        }

        for (int i = startIndex; i <= endIndex; ++i) {
            swap(nums[startIndex], nums[i]);

            permutation(startIndex + 1, endIndex, nums);

            swap(nums[startIndex], nums[i]);
        }
    }
};