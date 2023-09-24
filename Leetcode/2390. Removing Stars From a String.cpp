class Solution {
public:
    string removeStars(string s) {
        stack<char> stk;
        int i;
        char ch;

        for (i = 0; i < s.size(); ++i) {
            if (s[i] == '*') {
                if (!stk.empty()) {
                    stk.pop();
                }
            }
            else {
                stk.push(s[i]);
            }
        }

        string ans = "";

        while(!stk.empty()) {
            ans += stk.top();
            stk.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};