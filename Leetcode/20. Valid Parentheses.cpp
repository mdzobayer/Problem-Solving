class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        int i;
        bool ans = true;
        for (i = 0; i < s.size(); ++i) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                stk.push(s[i]);
            }
            else {
                if (stk.empty()) {
                    ans = false;
                    break;
                }
                if (stk.top() == MapOposit(s[i])) {
                    stk.pop();
                }
                else {
                    ans = false;
                    break;
                }
            }
        }
        if (ans && !stk.empty()) ans = false;

        return ans;
    }

    char MapOposit(char ch) {
        if (ch == ')') return '(';
        else if (ch == '}') return '{';
        else return '[';
    }
};