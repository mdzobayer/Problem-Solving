class Solution {
    int k, n;
    vector< vector<long long> > dp;
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        n = nums.size();
        this->k = k;

        dp.resize(n, vector<long long>(2, -1));

        return solve(0, 1, nums);
    }

    long long solve(int index, int isEven, vector<int>& nums) {
        if (index == n) {
            return isEven == 1 ? 0 : INT_MIN;
        }

        if (dp[index][isEven] != -1) {
            return dp[index][isEven];
        }

        long long noXorDone = nums[index] + solve(index + 1, isEven, nums);
        long long xorDone = (nums[index] ^ k) + solve(index + 1, isEven ^ 1, nums);

        return dp[index][isEven] = max(noXorDone, xorDone);
    }
};