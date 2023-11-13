class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        int a, b;
        int i;

        for (i = 0; i < tokens.size(); ++i) {
            if (tokens[i] == "+") {
                a = stk.top();
                stk.pop();
                b = stk.top();
                stk.pop();
                stk.push(a + b);
            }
            else if (tokens[i] == "-") {
                a = stk.top();
                stk.pop();
                b = stk.top();
                stk.pop();
                stk.push(b - a);
            }
            else if (tokens[i] == "*") {
                a = stk.top();
                stk.pop();
                b = stk.top();
                stk.pop();
                stk.push(a * b);
            }
            else if (tokens[i] == "/") {
                a = stk.top();
                stk.pop();
                b = stk.top();
                stk.pop();
                stk.push(b / a);
            }
            else {
                stk.push(stoi(tokens[i]));
            }
        }

        return stk.top();
    }
};