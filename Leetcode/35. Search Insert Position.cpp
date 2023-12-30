class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, mid, right = nums.size() - 1;

        auto it = upper_bound(nums.begin(), nums.end(), target);
        int index = (it - nums.begin());

        if (binary_search(nums.begin(), nums.end(), target)) --index;

        return index;
    }
};