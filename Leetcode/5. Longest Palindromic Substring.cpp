class Solution {
public:
    string longestPalindrome(string str) {
        int maxLps = 1, maxLpsStartIndex = 0;
        int i, j, k, n = str.size();
        bool dp[n][n];

        memset(dp, false, sizeof(dp));

        // one length palindrome
        for (i = 0; i < n; ++i) {
            dp[i][i] = true;
        }

        // two length palindrome
        for (i = 0; i < n - 1; ++i) {
            if (str[i] == str[i + 1]) {
                dp[i][i + 1] = true;
                if (maxLps < 2) {
                    maxLps = 2;
                    maxLpsStartIndex = i;
                }
            }
        }
        
        // greater then 2 palindrome
        for (k = 3; k <= n; ++k) {
            for (i = 0; i < n - k + 1; ++i) {
                j = i + k - 1;

                if (dp[i + 1][j - 1] && str[i] == str[j]) {
                    dp[i][j] = true;
                    if (k > maxLps) {
                        maxLps = k;
                        maxLpsStartIndex = i;
                    }
                }
            }
        }

        return str.substr(maxLpsStartIndex, maxLps);
    }

};