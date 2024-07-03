class Solution {
public:
    int minDifference(vector<int>& nums) {
        if (nums.size() <= 4) return 0;

        int i, n = nums.size();
        sort(nums.begin(), nums.end());

        if (n == 5) {
            int ans = nums[1] - nums[0];
            for (i = 2; i < n; ++i) {
                ans = min(ans, nums[i] - nums[i - 1]);
            }

            return ans;
        }

        return findAns(nums, 0, n - 1, 3);
    }

    int findAns(vector<int>& nums, int start, int end, int k) {
        if (k == 0) return nums[end] - nums[start];

        return min(findAns(nums, start + 1, end, k - 1), findAns(nums, start, end - 1, k - 1));
    }
};