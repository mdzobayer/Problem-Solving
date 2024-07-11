class Solution {
public:
    string reverseParentheses(string s) {
        int index = 0;
        string ans = findInner(s, index, false);

        return ans;
    }

    string findInner(string &s, int & index, bool isParentheses) {
        string str = "";
        int x = index;

        if (index >= s.size()) return str;

        while(index < s.size()) {
            if (s[index] >= 'a' && s[index] <= 'z') {
                str.push_back(s[index]);
                ++index;
            }
            else if (s[index] == '(') {
                ++index;
                str += findInner(s, index, true);
            }
            else {
                ++index;
                break;
            }
        }
        if (isParentheses) {
            reverse(str.begin(), str.end());
        }
        
        return str; 
    }
};