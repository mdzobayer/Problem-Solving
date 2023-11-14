class Solution {

public:
    int countPalindromicSubsequence(string s) {
        int i, j, ans = 0, n = s.size();
        vector<int> charCount(26, 0);
        vector< vector<int> > leftCount(n), rightCount(n);

        // left
        for (i = 0; i < n; ++i) {
            charCount[s[i] - 'a'] += 1;
            leftCount[i] = charCount;
        }
        // reset
        for (i = 0; i < 26; ++i) {
            charCount[i] = 0;
        }
        // right
        for (i = n - 1; i >= 0; --i) {
            charCount[s[i] - 'a'] += 1;
            rightCount[i] = charCount;
        }

        bool visited[26][26][26];
        memset(visited, true, sizeof(visited));

        for (i = 1; i < n - 1; ++i) {
            for (j = 0; j < 26; ++j) {
                if (leftCount[i - 1][j] > 0 && rightCount[i + 1][j] > 0 && visited[j][s[i] - 'a'][j]) {
                    visited[j][s[i] - 'a'][j] = false;
                    ans += 1;
                }
            }
        }

        return ans;
    }
};