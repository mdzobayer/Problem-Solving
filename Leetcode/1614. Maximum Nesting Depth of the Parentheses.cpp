class Solution {
public:
    int maxDepth(string s) {
        int currentDepth = 0, maxDepth = 0;

        for (char ch : s) {
            if (ch == '(') {
                ++ currentDepth;
            }
            else if (ch == ')') {
                -- currentDepth;
            }

            maxDepth = max(maxDepth, currentDepth);
        }

        return maxDepth;
    }
};