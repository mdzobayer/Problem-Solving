class Solution {
public:
    int specialArray(vector<int>& nums) {
        int i, ans = -1, n = nums.size();

        vector<int> freq(n + 1, 0);

        for (i = 0; i < n; ++i) {
            ++ freq[min(n, nums[i])];
        }

        int numGToEq = 0;
        for (i = n; i > 0; --i) {
            numGToEq += freq[i];
            if (i == numGToEq) {
                return i;
            }
        }

        return -1;
    }
};