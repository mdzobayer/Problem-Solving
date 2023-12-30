class Solution {
    int dp[1001][1001];
    string s;
public:
    bool isValidPalindrome(string s, int k) {
        memset(dp, -1, sizeof(dp));
        this->s = s;
        return (solve(0, s.size() - 1) <= k);
    }

    int solve(int left, int right) {
        if (left == right) return (0);
        if (left == right - 1) return s[left] != s[right];

        if (dp[left][right] != -1) return dp[left][right];

        int ans;
        if (s[left] == s[right]) {
            ans = solve(left + 1, right - 1);
        }
        else {
            ans = 1 + min(solve(left + 1, right), solve(left, right - 1));
        }

        return dp[left][right] = ans;
    }
};