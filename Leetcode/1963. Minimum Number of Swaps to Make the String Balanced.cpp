class Solution {
public:
    int minSwaps(string s) {
        stack<char> stk;

        int unbalance = 0;

        for (char ch : s) {
            if (ch == '[') {
                stk.push(ch);
            }
            else {
                if (!stk.empty()) stk.pop();
                else ++ unbalance;
            }
        }

        return (unbalance + 1) / 2;
    }
};