class Solution {
public:
    string parseTernary(string expression) {
        
        int i = expression.size() - 1; 
        stack<char> stack;

        while(i >= 0) {
            if (isdigit(expression[i]) || expression[i] == 'T' || expression[i] == 'F') {
                stack.push(expression[i]);
            }
            else if (expression[i] == '?') {
                char onTrue = stack.top();
                stack.pop();
                char onFalse = stack.top();
                stack.pop();

                stack.push(expression[i - 1] == 'T' ? onTrue : onFalse);
                --i;
            }

            --i;
        }

        string ans = "";
        ans.push_back(stack.top());

        return ans;
    }
};