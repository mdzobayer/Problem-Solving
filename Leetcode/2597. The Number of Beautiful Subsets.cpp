class Solution {
    unordered_map<int, int> freqCount;
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return countSubset(nums, k, 0) - 1;
    }

    int countSubset(vector<int>& nums, const int & k, int i) {
        if (i == nums.size()) {
            return 1;
        }

        int totalCount = countSubset(nums, k, i + 1);

        if (!freqCount[nums[i] - k]) {
            ++ freqCount[nums[i]];

            totalCount += countSubset(nums, k, i + 1);

            -- freqCount[nums[i]];
        }

        return totalCount;
    }
};