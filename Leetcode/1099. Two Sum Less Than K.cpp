class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        vector<int> vt;

        int i, j, ans = -1;

        for (i = 0; i < nums.size(); ++i) {
            for (j = i + 1; j < nums.size(); ++j) {
                if (nums[i] + nums[j] < k) {
                    vt.push_back(nums[i] + nums[j]);
                }
            }
        }
        if (vt.size() == 0) return -1;
        
        ans = vt[0];
        for (i = 1; i < vt.size(); ++i) {
            ans = max(ans, vt[i]);
        }

        return ans;
    }
};