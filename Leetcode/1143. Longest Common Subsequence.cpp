class Solution {
    vector<vector<int>> dp;
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        vector<int> aRow;
        for (int i = 0; i < 1000 + 5; ++i) {
            aRow.push_back(-1);
        }
        for (int i = 0; i < 1000 + 5; ++i) {
            dp.push_back(aRow);
        }

        return findLCS(0, 0, text1, text2);
    }

    int findLCS(int x, int y, const string & text1, const string & text2) {
        if (x >= text1.size() || y >= text2.size()) return (0);

        if (dp[x][y] != -1) return dp[x][y];

        int ans = max(findLCS(x + 1, y, text1, text2), findLCS(x, y + 1, text1, text2));
        if (text1[x] == text2[y]) {
            ans = max(ans, findLCS(x + 1, y + 1, text1, text2) + 1);
        }

        return dp[x][y] = ans;
    }
};