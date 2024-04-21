class Solution {
public:
    int largestUniqueNumber(vector<int>& nums) {
        vector<int> counts(1001, 0);
        int i;

        for (int num : nums) {
            counts[num] += 1;
        }

        for (i = 1000; i >= 0; --i) {
            if (counts[i] == 1) return i;
        }

        return -1;
    }
};