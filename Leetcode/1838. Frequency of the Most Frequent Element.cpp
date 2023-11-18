#define ll long long int
class Solution {
public:
    int maxFrequency(vector<int>& nums, const int k) {
        sort(nums.begin(), nums.end());

        ll left = 0, right, target, segment, slider, ans = 1, n = nums.size();
        segment = nums[left];

        for(right = 1; right < n; ++right) {
            target = nums[right];

            slider = right - left + 1;

            while ((((ll)slider * nums[right]) - ((ll)segment + nums[right])) > k && left < right) {
                segment -= nums[left];
                ++left;
                slider = right - left + 1;
            }
            ans = max(ans, slider);

            segment += target;
        }

        return ans;
    }
};