class Solution {
    int counts[256];
public:
    int lengthOfLongestSubstring(string s) {
        memset(counts, 0, sizeof(counts));
        int i, j, ans = 0;

        for (i = 0, j = 0; i < s.size(); ++i) {
            counts[s[i]] += 1;

            while(counts[s[i]] > 1) {
                counts[s[j]] -= 1;
                ++j;
            }

            ans = max(ans, i - j + 1);
        }

        return ans;
    }
};