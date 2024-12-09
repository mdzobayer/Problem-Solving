class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<bool> ans(queries.size(), false);
        vector<int> prefix(nums.size(), 0);
        prefix[0] = 0;
        int i, start, end;

        for (i = 1; i < nums.size(); ++i) {
            if (nums[i] % 2 == nums[i - 1] % 2) {
                prefix[i] = prefix[i - 1] + 1;
            }
            else {
                prefix[i] = prefix[i - 1];
            }
        }

        for (i = 0; i < queries.size(); ++i) {
            vector<int> query = queries[i];
            start = query[0];
            end = query[1];

            ans[i] = prefix[end] - prefix[start] == 0;
        }

        return ans;
    }
};