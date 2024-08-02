class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int opt1 = minimumSwapNeed(nums, 0);
        int opt2 = minimumSwapNeed(nums, 1);

        return min(opt1, opt2);
    }

    // Sliding window
    int minimumSwapNeed(vector<int> & nums, int val) {
        int i, n = nums.size(), totalValCount = 0;

        for (i = n - 1; i >= 0; --i) {
            if (nums[i] == val) {
                ++ totalValCount;
            }
        }

        if (totalValCount == 0 || totalValCount == n) return 0;

        int start = 0, end = 0, maximumValCount = 0, sliderValCount = 0;

        while(end < totalValCount) {
            if (nums[end++] == val) {
                ++ sliderValCount;
            }
        }

        maximumValCount = max(maximumValCount, sliderValCount);

        while(end < n) {
            if (nums[start++] == val) {
                -- sliderValCount;
            }

            if (nums[end++] == val) {
                ++ sliderValCount;
            }

            maximumValCount = max(maximumValCount, sliderValCount);
        }

        return totalValCount - maximumValCount;
    }
};