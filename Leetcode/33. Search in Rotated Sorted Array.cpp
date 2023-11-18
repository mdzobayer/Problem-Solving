class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        int ans, pivot = findPivot(nums, nums.size());

        if (nums[right] < target) {
            ans = binarySearch(nums, left, pivot - 1, target);
        }
        else {
            ans = binarySearch(nums, pivot, right, target);
        }

        return ans;
    }

    int findPivot(vector<int>& nums, int len) {
        int mid, left = 0, right = len - 1;

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

    int binarySearch(vector<int>& nums, int left, int right, int key) {
        int mid, ansIndex = -1;

        while(left <= right) {
            mid = (left + right) / 2;

            if (nums[mid] > key) {
                right = mid - 1;
            }
            else if (nums[mid] < key) {
                left = mid + 1;
            }
            else {
                ansIndex = mid;
                break;
            }
        }

        return ansIndex;
    }
};