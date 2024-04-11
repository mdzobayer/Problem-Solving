class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<char> stack;

        for (char digit : num) {
            while(stack.size() > 0 && k > 0 && stack.back() > digit) {
                stack.pop_back();
                -- k;
            }
            stack.push_back(digit);
        }

        while(k > 0) {
            stack.pop_back();
            --k;
        }

        string s = "";
        bool leadZero = true;
        for (int i = 0; i < stack.size(); ++i) {
            if (leadZero && stack[i] == '0') continue;
            leadZero = false;
            s += stack[i];
        }

        if (s == "") s = "0";
        return s;
    }
};