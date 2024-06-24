class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int i, n = nums.size();

        vector<bool> flipped(nums.size(), false);
        int flipCount = 0, validFlipsFromPastWindow = 0;

        for (i = 0; i < n; ++i) {
            if (i >= k) {
                // Decrease count of valid flips from the past window if needed
                if (flipped[i - k]) {
                    -- validFlipsFromPastWindow;
                }
            }

            // Check if current bit needs to be flipped
            if (validFlipsFromPastWindow % 2 == nums[i]) {
                // If flipping the window extends beyond the array length,
                // return -1
                if (i + k > n) {
                    return -1;
                }
                // Increment the count of valid flips and mark current as
                // flipped
                ++ validFlipsFromPastWindow;
                flipped[i] = true;
                ++ flipCount;
            }
        }

        return flipCount;
    }
};