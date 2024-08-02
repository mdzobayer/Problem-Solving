class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int i, n = nums.size();
        vector<bool> present(n + 1, false);

        for(i = 0; i < n; ++i) {
            present[nums[i]] = true;
        }

        vector<int> ans;
        for (i = 1; i <= n; ++i) {
            if (!present[i]) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};