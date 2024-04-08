class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int numsOf0 = 0, i, j, ans = 0;

        for (i = 0, j = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                ++ numsOf0;
            }

            while(numsOf0 > 1) {
                if (nums[j] == 0) {
                    -- numsOf0;
                }
                ++j;
            }

            ans = max(ans, i - j + 1);
        }

        return ans;
    }
};