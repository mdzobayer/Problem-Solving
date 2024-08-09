class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans(n * 2);
        int i = 0, j = 0;

        while(i < n) {
            ans[j++] = nums[i];
            ans[j++] = nums[i + n];
            ++i;
        }

        return ans;
    }
};