class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> ans(nums.begin(), nums.end());
        mergeSort(ans, 0, ans.size() - 1);
        return ans;
    }

    void mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right) return;

        int mid = (left + right) / 2;

        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);

        vector<int> temp(right - left + 1);

        int cursor1 = left, cursor2 = mid + 1, cursor3 = 0;

        while(cursor1 <= mid && cursor2 <= right) {
            if (nums[cursor1] < nums[cursor2]) {
                temp[cursor3 ++] = nums[cursor1 ++];
            }
            else {
                temp[cursor3 ++] = nums[cursor2 ++];
            }
        }

        while(cursor1 <= mid) {
            temp[cursor3 ++] = nums[cursor1 ++];
        }

        while(cursor2 <= right) {
            temp[cursor3 ++] = nums[cursor2 ++];
        }

        for (cursor1 = 0, cursor2 = left; cursor1 < temp.size(); ++ cursor1) {
            nums[cursor2++] = temp[cursor1];
        }
    }
};