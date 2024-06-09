class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int i, ans = 0, prefixMod = 0, n = nums.size();
        unordered_map<int, int> hashMap;
        hashMap[0] = 1;

        for (i = 0; i < n; ++i) {
            prefixMod = ((prefixMod + nums[i]) % k + k) % k;
            ans += hashMap[prefixMod];
            ++ hashMap[prefixMod];
        }

        return ans;
    }
};