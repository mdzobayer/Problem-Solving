class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> stk;

        for (char ch : expression) {
            if (ch == ')') {
                vector<char> values;

                while(stk.top() != '(') {
                    values.push_back(stk.top());
                    stk.pop();
                }
                stk.pop();
                char op = stk.top();
                stk.top();

                char result = evaluateSubExpr(op, values);
                stk.push(result);
            }
            else if (ch != ',') {
                stk.push(ch);
            }
        }

        return stk.top() == 't';
    }

    char evaluateSubExpr(char op, vector<char>&values) {
        if (op == '!') return values[0] == 't' ? 'f' : 't';

        if (op == '&') {
            for (char value : values) {
                if (value == 'f') return 'f';
            }
            return 't';
        }
        else if (op == '|') {
            for (char value : values) {
                if (value == 't') return 't';
            }
            return 'f';
        }

        return 'f';
    }
};