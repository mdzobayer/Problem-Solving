class Solution {
public:
    int slidingWindowAtMost(vector<int> & nums, int goal) {
        int start = 0, end, sliderSum = 0, totalCount = 0;

        for (end = 0; end < nums.size(); ++end) {
            sliderSum += nums[end];

            while(start <= end && sliderSum > goal) {
                sliderSum -= nums[start];
                ++start;
            }

            totalCount += end - start + 1;
        }

        return totalCount;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {

        return slidingWindowAtMost(nums, goal) - slidingWindowAtMost(nums, goal - 1);
    }
};