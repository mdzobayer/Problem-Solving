class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0;

        for (int i = 0; i < s.size(); ++i) {
            ans += countPalindromesAroundCenter(s, i, i);
            ans += countPalindromesAroundCenter(s, i, i + 1);
        }

        return ans;
    }

    int countPalindromesAroundCenter(const string & str, int lo, int hi) {
        int ans = 0;

        while(lo >= 0 && hi < str.size()) {
            if (str[lo] != str[hi]) break;

            -- lo;
            ++ hi;
            ++ ans;
        }

        return ans;
    }
};