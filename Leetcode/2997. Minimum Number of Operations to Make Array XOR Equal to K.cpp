class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans = 0, xorOfNums = 0;
        for (int num : nums) {
            xorOfNums ^= num;
        }

        while(k || xorOfNums) {
            if ((k % 2) != (xorOfNums % 2)) {
                ++ ans;
            }

            k >>= 1;
            xorOfNums >>= 1;
        }

        return ans;
    }
};