class Solution {
    int dp[101];
public:
    int numDecodings(string s) {
        memset(dp, -1, sizeof(dp));
        
        return solve(0, s);
    }

    int solve(int index, string & s) {
        if (index >= s.size()) {
            return 1;
        }

        if (s[index] == '0') return 0;

        if(dp[index] != -1) return dp[index];

        dp[index] = solve(index + 1, s);

        if (index + 1 < s.size() && genNum(index, s) <= 26) {
            dp[index] += solve(index + 2, s);
        }

        return dp[index];
    }

    int genNum(int index, string & s) {
        int num = 0;
        num += s[index] - '0';

        num *= 10;
        num += s[index + 1] - '0';
        return num;
    }
};