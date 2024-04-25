class Solution {
    vector<vector<int>> dp;
    int n, k;
public:
    int longestIdealString(string s, int k) {
        n = s.size();
        this->k = k;

        if (n == 1) return 1;

        dp.resize(n + 1, vector<int>(26, -1));

        int i, ans = 0;
        for (i = 0; i < s.size() - 1; ++ i) {
            ans = max(ans, solve(s, i + 1, s[i] - 'a') + 1);
        }

        return ans;
    }

    int solve(string & s, int index, int lastChar) {
        if (index >= s.size()) return (0);

        if (dp[index][lastChar] != -1) return dp[index][lastChar];

        int ans = 0;
        if (abs(lastChar - (s[index] - 'a')) <= k) {
            ans = solve(s, index + 1, s[index] - 'a') + 1;
        }

        ans = max(ans, solve(s, index + 1, lastChar));

        return dp[index][lastChar] = ans;
    }
};