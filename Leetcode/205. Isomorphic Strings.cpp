class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;

        int i;
        map<char, char> dic;
        bool ans = true;
        vector<bool> mapped(300, false);

        for (i = 0; i < s.size(); ++i) {
            if (dic.find(s[i]) == dic.end()) {

                if (mapped[t[i]]) {
                    ans = false;
                    break;
                }

                dic[s[i]] = t[i];
                mapped[t[i]] = true;
            }
            else if (dic[s[i]] != t[i]) {
                ans = false;
                break;
            }
        }

        return ans;
    }
};