class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int i, n = nums.size();
        for (i = 1; i < n - 1; i += 2) {
            nums[i] ^= nums[i + 1];
            nums[i + 1] ^= nums[i];
            nums[i] ^= nums[i + 1];
        }
    }
};