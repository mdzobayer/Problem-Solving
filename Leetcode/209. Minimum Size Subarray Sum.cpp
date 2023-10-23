class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int len = 1, minLen = INT_MAX;
        int subSum = nums[0];
        
        int i = 1;
        while(subSum < target && i < nums.size()) {
            subSum += nums[i];
            ++i;
            ++len;
        }

        while(subSum >= target || i < nums.size()) {
            if (subSum >= target) {
                minLen = min(minLen, len);

                subSum -= nums[i - len];
                --len;

                // if (subSum < 0) {
                //     subSum = 0;
                //     len = 0;
                // }
            }
            else if (i < nums.size()) {
                subSum += nums[i];
                ++len;
                ++i;
            }
        }

        return minLen == INT_MAX ? 0 : minLen;
    }
};