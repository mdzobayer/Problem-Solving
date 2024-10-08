class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int mid, left = 0, right = nums.size() - 1;

        while(left < right) {
            mid = (left + right) / 2;

            if (nums[mid] > nums[mid + 1]) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }

        return left;
    }
};