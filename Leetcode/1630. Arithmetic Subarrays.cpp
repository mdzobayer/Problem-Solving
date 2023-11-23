class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int i, j, queryLen = l.size();
        vector<bool> ans(queryLen);

        for(i = 0; i < queryLen; ++i) {
            ans[i] = isArithmetic(l[i], r[i], nums);
        }

        return ans;
    }

    bool isArithmetic(int left, int right, vector<int>& nums) {
        int i, j, diff;
        vector<int> sortedSubArray(right - left + 1);
        for (i = left, j = 0; i <= right; ++i, ++j) {
            sortedSubArray[j] = nums[i];
        }

        sort(sortedSubArray.begin(), sortedSubArray.end());

        diff = sortedSubArray[1] - sortedSubArray[0];

        for (i = 2; i < sortedSubArray.size(); ++i) {
            if (sortedSubArray[i] - sortedSubArray[i - 1] != diff) return false;
        }

        return true;
    }
};