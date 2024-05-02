class Solution {
public:
    long long countPairs(vector<int>& nums1, vector<int>& nums2) {
        long long i, ans = 0, n = nums1.size();
        vector<long long> numberDiff(n);

        for (i = 0; i < n; ++i) {
            numberDiff[i] = ((long long)nums1[i] - nums2[i]);
        }

        sort(numberDiff.begin(), numberDiff.end());

        int left = 0, right = n - 1;

        while(left < right) {
            if (numberDiff[left] + numberDiff[right] > 0) {
                ans += right - left;
                --right;
            }
            else ++ left;
        }

        return ans;
    }
};