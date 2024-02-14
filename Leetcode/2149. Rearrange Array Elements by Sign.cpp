class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos, neg, ans;
        int i, n = nums.size();
        for (i = 0; i < n; ++i) {
            if (nums[i] > 0) pos.push_back(nums[i]);
            else neg.push_back(nums[i]);
        }

        n /= 2;
        for (i = 0; i < n; ++i) {
            ans.push_back(pos[i]);
            ans.push_back(neg[i]);
        }

        return ans;
    }
};