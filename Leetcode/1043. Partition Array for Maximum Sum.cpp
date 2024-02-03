class Solution {
public:

    int k, n, dp[501];

    int solve(vector<int>& arr, int start) {
        if (start >= n) return 0;

        if (dp[start] != -1) return dp[start];

        int currMax = arr[start], ans = 0, end = min(n, start + k);
        for (int i = start; i < end; ++i) {
            currMax = max(currMax, arr[i]);
            ans = max(ans, currMax * (i - start + 1) + solve(arr, i + 1));
        }

        return dp[start] = ans;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        this->k = k;
        n = arr.size();

        memset(dp, -1, sizeof(dp));

        return solve(arr, 0);
    }
};