class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long int ans = 0;
        int i, minPos = -1, maxPos = -1, leftPos = -1;

        for (i = 0; i < nums.size(); ++i) {
            
            // Store most recent left position
            if (nums[i] < minK || nums[i] > maxK) {
                leftPos = i;
            }

            // Store most recent maxK and minK
            if (nums[i] == minK) {
                minPos = i;
            }
            if (nums[i] == maxK) {
                maxPos = i;
            }

            ans += max(0, min(maxPos, minPos) - leftPos);
        }

        return ans;
    }
};