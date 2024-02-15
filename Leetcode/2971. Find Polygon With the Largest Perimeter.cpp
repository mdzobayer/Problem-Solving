class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        long long int i, ans = -1, sum = 0, n = nums.size();
        sort(nums.begin(), nums.end());

        for (i = 0; i < n; ++i) {
            if (nums[i] < sum) {
                ans = nums[i] + sum;
            }
            sum += nums[i];
        }
        
        return ans;
    }
};