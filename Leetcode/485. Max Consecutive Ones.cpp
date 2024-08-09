class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCount = 0, count = 0;

        for (int item : nums) {
            if (item == 1) {
                ++count;
                maxCount = max(maxCount, count);
            }
            else count = 0;
        }
        
        return maxCount;
    }
};