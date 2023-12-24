class Solution {
public:
    int calculate(string s) {
        
        int i, operand, sign, result, n = s.size();
        stack<int> stk;

        operand = 0;
        sign = 1;
        result = 0;

        for (i = 0; i < n; ++i) {
            if (isdigit(s[i])) {
                operand *= 10;
                operand += s[i] - '0';
            }
            else if (s[i] == '+') {
                result += sign * operand;
                sign = 1;
                operand = 0;
            }
            else if (s[i] == '-') {
                result += sign * operand;
                sign = -1;
                operand = 0;
            }
            else if (s[i] == '(') {
                stk.push(result);
                stk.push(sign);

                result = 0;
                sign = 1;
                operand = 0;
            }
            else if (s[i] == ')') {
                result += sign * operand;

                result *= stk.top();
                stk.pop();
                result += stk.top();
                stk.pop();

                sign = 1;
                operand = 0;
            }
        }

        result += sign * operand;

        return result;
    }
};