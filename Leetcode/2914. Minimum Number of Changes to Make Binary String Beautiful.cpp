class Solution {
public:
    int minChanges(string s) {
        int i, ans = 0;

        for (i = 1; i < s.size(); i += 2) {
            if (s[i] != s[i - 1]) ++ ans;
        }

        return ans;
    }
};