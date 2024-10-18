class Solution {
    int target;
public:
    int countMaxOrSubsets(vector<int>& nums) {
        target = 0;

        for (int num : nums) target |= num;

        return countSubsets(nums, 0, 0);
    }

    int countSubsets(vector<int>& nums, int index, int currOr) {
        if (index == nums.size()) {
            return (currOr == target) ? 1 : 0;
        }

        int countWithout = countSubsets(nums, index + 1, currOr);
        int countWith = countSubsets(nums, index + 1, currOr | nums[index]);

        return countWithout + countWith;
    }
};