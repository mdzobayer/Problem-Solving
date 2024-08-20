class Solution {
    int n;
    vector< vector<int> > dp;
    vector<int> suffixSum;

public:
    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        dp.resize(piles.size(), vector<int>(piles.size()));
        suffixSum.resize(n);
        suffixSum = piles;

        for (int i = n - 2; i >= 0; --i) {
            suffixSum[i] += suffixSum[i + 1];
        }
        
        return maxStone(1, 0);
    }

    int maxStone(int maxTillNow, int currIndex) {
        if (currIndex + 2 * maxTillNow >= n) {
            return suffixSum[currIndex];
        }

        if (dp[maxTillNow][currIndex] > 0) return dp[maxTillNow][currIndex];

        int res = INT_MAX;

        for (int i = 1; i <= 2 * maxTillNow; ++i) {
            res = min(res, maxStone(max(i, maxTillNow), currIndex + i));
        }

        return dp[maxTillNow][currIndex] = suffixSum[currIndex] - res;
    }
};