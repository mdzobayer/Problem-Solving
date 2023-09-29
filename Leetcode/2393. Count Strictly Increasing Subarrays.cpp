class Solution {
public:
    long long countSubarrays(vector<int>& nums) {

        long long int increasingSubarrays = 0, x;

        int i, cnt = 1, subarraygraterthenOne = 0;
        for (i = 1; i < nums.size(); ++i) {
            if(nums[i] > nums[i - 1]) {
                ++cnt;
            }
            else {
                if (cnt > 1) {
                    subarraygraterthenOne += cnt;
                    increasingSubarrays += ((cnt * (long long int)cnt) + cnt)/2;
                }
                cnt = 1;
            }
        }

        if (cnt > 1) {
            subarraygraterthenOne += cnt;
            increasingSubarrays += ((cnt * (long long int)cnt) + cnt)/2;
        }

        increasingSubarrays += (nums.size() - subarraygraterthenOne);

        return increasingSubarrays;
    }
};