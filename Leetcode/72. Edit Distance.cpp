
class Solution {
    int dp[500+5][500+5];
public:
    int minDistance(string word1, string word2) {
        memset(dp, -1, sizeof(dp));
        return calculateMinDistance(0, 0, word1, word2);
    }

    int calculateMinDistance(int i, int j, string & word1, string & word2) {

        if (i >= word1.size()) {
            return abs((int)word2.size() - j);
        }

        if (j >= word2.size()) {
            return abs((int)word1.size() - i);
        }

        if (dp[i][j] != -1) return dp[i][j];

        int ans = INT_MAX;
        if (word1[i] == word2[j]) {
            ans = min(ans, calculateMinDistance(i + 1, j + 1, word1, word2));
        }
        else {
            // delete from word1
            ans = min(ans, calculateMinDistance(i + 1, j, word1, word2) + 1);

            // replace on word1
            ans = min(ans, calculateMinDistance(i + 1, j + 1, word1, word2) + 1);

            // insert into word1
            ans = min(ans, calculateMinDistance(i, j + 1, word1, word2) + 1);
        }

        return dp[i][j] = ans;
    }
};