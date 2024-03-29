class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxElement = *max_element(nums.begin(), nums.end());
        long long int left, right, ans = 0, cnt = 0;
        
        for (left = 0, right = 0; right < nums.size(); ++right) {
            if (nums[right] == maxElement) {
                -- k;
            }

            while(k == 0) {
                if (nums[left] == maxElement) {
                    ++ k;
                }
                ++ left;
            }
            ans += left;
        }

        return ans;
    }
};