class Solution {
public:
    long long subsequenceSumOr(vector<int>& nums) {
        long long result = 0, prefixSum = 0;

        for (int num : nums) {
            prefixSum += num;
            result |= num | prefixSum;
        }

        return result;
    }
};