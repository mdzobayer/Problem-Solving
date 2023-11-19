class Solution {
public:
    int findMin(vector<int>& nums) {
        int pivotIndex = findPivot(nums);

        return nums[pivotIndex];
    }

    int findPivot(vector<int>& nums) {
        int mid, left = 0, len = nums.size(), right = len - 1;

        while(left <= right) {
            mid = (left + right) / 2;

            if (nums[mid] > nums[len - 1]) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return left;
    }
};