class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        int minLimit = INT_MIN;
        stack<int> stack;

        for (int num : preorder) {
            
            while(!stack.empty() && stack.top() < num) {
                minLimit = stack.top();
                stack.pop();
            }

            if (minLimit >= num) return false;
            stack.push(num);
        }

        return true;
    }
};