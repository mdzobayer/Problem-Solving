class Solution {
public:
    string makeGood(string s) {
        string ans = s;
        while(true) {
            string good = solve(ans);
            if (good == ans) {
                break;
            }
            ans = good;
        }

        return ans;
    }

    string solve(string s) {
        string ans = "";

        if (s.size() == 0) return ans;

        int i;
        for (i = 0; i < s.size() - 1; ++i) {
            if (s[i] >= 'A' && s[i] <= 'Z') {
                if (s[i] + 32 != s[i + 1]) {
                    ans += s[i];
                }
                else ++i;
            }
            else if (s[i] >= 'a' && s[i] <= 'z') {
                if (s[i] - 32 != s[i + 1]) {
                    ans += s[i];
                }
                else ++i;
            }
        }

        if (i < s.size()) {
            ans += s[i];
            ++i;
        }
        
        return ans;
    }
};