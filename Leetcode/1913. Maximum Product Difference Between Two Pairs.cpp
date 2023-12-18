class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int ans, len = nums.size();
        ans = (nums[len - 1] * nums[len - 2]) - (nums[1] * nums[0]);

        return ans;
    }
};