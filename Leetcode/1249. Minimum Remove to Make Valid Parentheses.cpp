class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans = "";
        int i, available = 0;

        s = clearFront(s);
        s = clearBack(s);

        for (i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                ++ available;
                ans += s[i];
            }
            else if (s[i] == ')') {
                if (available > 0) {
                    -- available;
                    ans += s[i];
                }
            }
            else {
                ans += s[i];
            }
        }

        s = ans;
        ans = "";
        available = 0;

        for (i = s.size() - 1; i >= 0; --i) {
            if (s[i] == ')') {
                ++ available;
                ans += s[i];
            }
            else if (s[i] == '(') {
                if (available > 0) {
                    -- available;
                    ans += s[i];
                }
            }
            else {
                ans += s[i];
            }
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }

    string clearBack(string & s) {
        string ans = "";
        int i, n = s.size();
        bool found = true;

        for (i = n - 1; i >= 0; --i) {
            if (s[i] == ')') {
                found = false;
            }

            if (s[i] == '(' && found) {
                continue;
            }
            else {
                ans += s[i];
            }
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }

    string clearFront(string & s) {
        string ans = "";
        int i, n = s.size();
        bool found = true;

        for (i = 0; i < n; ++i) {
            if (s[i] == '(') {
                found = false;
            }

            if (s[i] == ')' && found) {
                continue;
            }
            else {
                ans += s[i];
            }
        }

        return ans;
    }
};