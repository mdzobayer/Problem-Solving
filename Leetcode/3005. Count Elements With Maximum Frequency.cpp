class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> counts(101, 0);
        int i, maximum = 0, ans = 0;

        for (i = 0; i < nums.size(); ++i) {
            counts[nums[i]] += 1;
            maximum = max(maximum, counts[nums[i]]);
        }

        for (i = 0; i < 101; ++i) {
            if (counts[i] == maximum) {
                ans += counts[i];
            }
        }

        return ans;
    }
};