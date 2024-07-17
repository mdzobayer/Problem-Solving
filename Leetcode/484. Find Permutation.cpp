class Solution {
public:
    vector<int> findPermutation(string s) {
        vector<int> result;
        stack<int> stack;

        for (int i = 1; i <= s.size(); ++i) {
            if (s[i - 1] == 'D') {
                stack.push(i);
            }
            else {
                result.push_back(i);
                while(!stack.empty()) {
                    result.push_back(stack.top());
                    stack.pop();
                }
            }
        }

        stack.push(s.size() + 1);
        while(!stack.empty()) {
            result.push_back(stack.top());
            stack.pop();
        }

        return result;
    }
};