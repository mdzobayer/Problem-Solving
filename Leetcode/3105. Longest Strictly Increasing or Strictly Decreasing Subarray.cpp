class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int i, ans = 0, counter = 1, n = nums.size();

        for (i = 1; i < n; ++i) {
            if (nums[i] > nums[i - 1]) {
                ++ counter;
            }
            else {
                ans = max(ans, counter);
                counter = 1;
            }
        }

        ans = max(ans, counter);

        counter = 1;

        for (i = 1; i < n; ++i) {
            if (nums[i] < nums[i - 1]) {
                ++ counter;
            }
            else {
                ans = max(ans, counter);
                counter = 1;
            }
        }

        ans = max(ans, counter);

        return ans;
    }
};