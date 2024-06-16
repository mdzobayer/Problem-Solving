class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int i = 0, patchRequired = 0;
        long long int miss = 1;

        while(miss <= n) {
            if (i < nums.size() && nums[i] <= miss) {
                miss += nums[i];
                ++ i;
            }
            else {
                miss += miss;
                ++ patchRequired;
            }
        }

        return patchRequired;
    }
};