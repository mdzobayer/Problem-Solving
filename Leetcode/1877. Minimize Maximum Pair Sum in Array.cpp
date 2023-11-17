class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int i, ans = 0, left = 0, right = nums.size() - 1;

        while(left < right) {
            ans = max(ans, (nums[left] + nums[right]));

            ++left;
            --right;
        }

        return ans;
    }
};