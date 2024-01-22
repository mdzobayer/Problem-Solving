class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int i, len = nums.size();
        vector<int> ans, counts(10001, 0);

        for (i = 0; i < len; ++i) {
            counts[nums[i]] += 1;
        }

        for (i = 1; i <= len; ++i) {
            if (counts[i] > 1) {
                ans.push_back(i);
            }
        }

        for (i = 1; i <= len; ++i) {
            if (counts[i] == 0) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};