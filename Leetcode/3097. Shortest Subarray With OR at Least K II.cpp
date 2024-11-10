class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int minLength = INT_MAX, windowStart = 0, windowEnd = 0;

        vector<int> bitCounts(32, 0);

        while(windowEnd < nums.size()) {
            updateBitCounts(bitCounts, nums[windowEnd], 1);

            while(windowStart <= windowEnd && convertBiCountsToNumber(bitCounts) >= k) {
                minLength = min(minLength, windowEnd - windowStart + 1);

                updateBitCounts(bitCounts, nums[windowStart], - 1);
                ++windowStart;
            }

            ++windowEnd;
        }

        return minLength == INT_MAX ? -1 : minLength;
    }

    void updateBitCounts(vector<int>& bitCounts, int number, int delta) {
        for (int i = 0; i < 32; ++i) {
            if ((number >> i) & 1) {
                bitCounts[i] += delta;
            }
        }
    }

    int convertBiCountsToNumber(const vector<int>& bitCounts) {
        int result = 0;

        for (int i = 0; i < 32; ++i) {
            if (bitCounts[i] != 0) {
                result |= (1 << i);
            }
        }

        return result;
    }
};