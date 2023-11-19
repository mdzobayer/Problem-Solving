class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int i, ans = 0, last = 0, maxElement = 0;
        // find maxElement
        for (i = 0; i < nums.size(); ++i) {
            maxElement = max(maxElement, nums[i]);
        }
        // store elements count
        vector<int> counts(maxElement + 1, 0);
        for (i = 0; i < nums.size(); ++i) {
            counts[nums[i]] += 1;
        }

        for (i = maxElement; i >= 0; --i) {
            if (counts[i] > 0) {
                ans += last;
                last += counts[i];
            }
        }

        return ans;
    }
};