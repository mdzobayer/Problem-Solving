class Solution {
public:
    int scoreOfString(string s) {
        int i, ans = 0;
        for (i = 1; i < s.size(); ++i) {
            ans += abs(s[i] - s[i - 1]);
        }

        return ans;
    }
};