class Solution {
public:
    int numberOfSpecialSubstrings(string s) {
        int i, j, count, ans = 0, n = s.size();
        vector<int> freq(26, 0);

        for (i = 0, j = 0; i < n; ++i) {
            ++ freq[s[i] - 'a'];

            while(freq[s[i] - 'a'] > 1) {
                -- freq[s[j] - 'a'];
                ++j;
            }

            count = i - j + 1;
            ans += count;
        }

        return ans;
    }
};