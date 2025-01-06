class Solution {
public:
    vector<int> minOperations(string boxes) {
        int i, n = boxes.size();
        int ballsToLeft = 0, movesToLeft = 0, ballsToRight = 0, movesToRight = 0;
        vector<int> ans(n, 0);

        for (i = 0; i < n; ++i) {
            ans[i] += movesToLeft;
            ballsToLeft += boxes[i] - '0';
            movesToLeft += ballsToLeft;

            int j = n - 1 - i;
            ans[j] += movesToRight;
            ballsToRight += boxes[j] - '0';
            movesToRight += ballsToRight;
        }

        return ans;
    }
};