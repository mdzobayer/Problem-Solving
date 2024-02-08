class Solution {
    vector<int> perfectSq;
    int len;
    int dp[10000+5];
public:
    int solve(int remain) {
        if (remain == 0) return 0;
        if (remain < 0) return 100000;

        if (dp[remain] != -1) return dp[remain];

        int ans = 100000;

        for (int i = 0; i < len; ++i) {
            if (perfectSq[i] > remain) break;
            ans = min(ans, solve(remain - perfectSq[i]) + 1);
        }

        return dp[remain] = ans;
    }

    int numSquares(int n) {
        
        int i, square;

        for (i = 1; i <= n; ++i) {
            square = i * i;
            if (square > n) break;
            perfectSq.push_back(square);
        }

        len = perfectSq.size();
        memset(dp, -1, sizeof(dp));

        return solve(n);
    }
};