class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int i, prefixMod = 0, n = nums.size();

        unordered_map<int, int> hashMap;
        hashMap[0] = -1;

        for (i = 0; i < n; ++i) {
            prefixMod += nums[i];
            prefixMod %= k;

            if (hashMap.find(prefixMod) != hashMap.end()) {
                if (i - hashMap[prefixMod] > 1) {
                    return true;
                }
            }
            else {
                hashMap[prefixMod] = i;
            }
        }

        return false;
    }
};