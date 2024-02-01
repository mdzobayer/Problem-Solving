class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int i, r, len = nums.size();

        sort(nums.begin(), nums.end());

        vector<vector<int>> ans, empty;
        vector<int> row;

        if (len % 3 != 0) return empty;

        for (i = 0, r = 0; i < len; i += 3, ++ r) {
            // Validity check
            if ((nums[i + 2] - nums[i + 1] > k) || (nums[i + 1] - nums[i] > k)
            || (nums[i + 2] - nums[i] > k)) {
                return empty;
            }

            ans.push_back(row);
            ans[r].push_back(nums[i]);
            ans[r].push_back(nums[i + 1]);
            ans[r].push_back(nums[i + 2]);
        }

        return ans;
    }
};