class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        int i, len = nums.size(), majority = len / 2, counter = 0;

        for (i = 0; i < len; ++i) {
            if (nums[i] == target) {
                ++ counter;

                if (counter > majority) return true;
            }
        }

        return false;
    }
};