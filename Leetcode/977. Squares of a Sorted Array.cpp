class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i = 0, n = nums.size();

        for (i = 0; i < n; ++i) {
            nums[i] = nums[i] * nums[i];
        }

        sort(nums.begin(), nums.end());

        return nums;
    }
};