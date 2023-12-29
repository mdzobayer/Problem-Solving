class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int i, singleMax = nums[0], maximum = 0, maxSoFar = 0;

        for (i = 0; i < nums.size(); ++i) {
            singleMax = max(singleMax, nums[i]);
            maxSoFar += nums[i];
            if (maxSoFar < 0) maxSoFar = 0;
            maximum = max(maximum, maxSoFar);
        }


        if (singleMax < 0) return singleMax;
        return maximum;
    }
};