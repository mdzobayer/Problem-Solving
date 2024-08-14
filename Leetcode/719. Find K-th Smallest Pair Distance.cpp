class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        vector<int> freq(10001, 0);
        int i, j, maxNum = 0, n = nums.size();

        maxNum = *max_element(nums.begin(), nums.end());
        vector<int> distanceBucket(maxNum + 1, 0);

        for (i = 0; i < n; ++i) {
            for (j = i + 1; j < n; ++j) {
                int distance = abs(nums[i] - nums[j]);
                ++ distanceBucket[distance];
            }
        }

        for (i = 0; i <= maxNum; ++i) {
            k -= distanceBucket[i];

            if (k <= 0) return i;
        }

        return -1;
    }
};