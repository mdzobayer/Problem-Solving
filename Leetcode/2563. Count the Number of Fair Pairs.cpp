class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());

        return binarySearch(nums, upper + 1) - binarySearch(nums, lower);
    }

    long long binarySearch(vector<int> & nums, int value) {
        int left = 0, right = nums.size() - 1;
        long long result = 0;

        while(left < right) {
            int sum = nums[left] + nums[right];

            if (sum < value) {
                result += (right - left);
                ++left;
            }
            else {
                -- right;
            }
        }

        return result;
    }
};