class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int recentElement = nums[0];
        int i, recentCount = 1, availableIndex = 1;

        for (i = 1; i < nums.size(); ++i) {
            if (nums[i] != recentElement) {

                if (recentCount >= 2) {
                    nums[availableIndex] = recentElement;
                    ++ availableIndex;
                }

                // reassign
                recentElement = nums[i];
                recentCount = 1;

                nums[availableIndex] = recentElement;
                ++ availableIndex;
            }
            else {
                ++ recentCount;
            }
        }

        if (recentCount >= 2) {
            nums[availableIndex] = recentElement;
            ++ availableIndex;
        }

        return availableIndex;
    }
};