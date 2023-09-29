class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool isIncreasing = true, isDecreasing = true;
        int i;

        for (i = 1; i < nums.size(); ++i) {
            if (nums[i] < nums[i - 1]) {
                isIncreasing = false;
            }

            if (nums[i] > nums[i - 1]) {
                isDecreasing = false;
            }

            if (!isIncreasing && !isDecreasing) break;
        }

        return (isIncreasing || isDecreasing);
    }
};