class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int left, right = 0, ans = 0;

        for (left = 0; left < nums.size(); ++left) {
            while(right < nums.size() && nums[right] - nums[left] <= 2 * k) {
                ++right;
            }

            ans = max(ans, right - left);
        }

        return ans;
    }
};