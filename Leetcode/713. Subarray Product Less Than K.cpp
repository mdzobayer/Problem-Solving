class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;

        int left, right, ans = 0, product = 1;

        for (left = 0, right = 0; right < nums.size(); ++right) {
            product *= nums[right];

            while(product >= k) {
                product /= nums[left];
                ++left;
            }

            ans += right - left + 1;
        }

        return ans;
    }
};