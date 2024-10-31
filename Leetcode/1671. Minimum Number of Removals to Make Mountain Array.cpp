class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int i, j, n = nums.size();

        vector<int> lisLength(n, 1), ldsLength(n, 1);

        for (i = 0; i < n; ++i) {
            for (j = i - 1; j >= 0; --j) {
                if (nums[i] > nums[j]) {
                    lisLength[i] = max(lisLength[i], lisLength[j] + 1);
                }
            }
        }

        for (i = n - 1; i >= 0; --i) {
            for (j = i + 1; j < n; ++j) {
                if (nums[i] > nums[j]) {
                    ldsLength[i] = max(ldsLength[i], ldsLength[j] + 1);
                }
            }
        }

        int minRemovals = INT_MAX;

        for (i = 0; i < n; ++i) {
            if (lisLength[i] > 1 && ldsLength[i] > 1) {
                minRemovals = min(minRemovals, n - lisLength[i] - ldsLength[i] + 1);
            }
        }

        return minRemovals;
    }
};