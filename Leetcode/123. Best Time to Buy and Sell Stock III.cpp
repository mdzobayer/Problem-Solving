class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i, j, len = prices.size();

        if (len == 1) return 0;

        vector<int> leftProfit(len, 0), rightProfit(len + 1, 0);
        int leftMin = prices[0];
        int rightMax = prices[len - 1];

        for (i = 1; i < len; ++i) {
            leftProfit[i] = max(leftProfit[i - 1], prices[i] - leftMin);
            leftMin = min(leftMin, prices[i]);

            j = len - 1 - i;
            rightProfit[j] = max(rightProfit[j + 1], rightMax - prices[j]);
            rightMax = max(rightMax, prices[j]);
        }
        
        int ans = 0;
        for (i = 0; i < len; ++i) {
            ans = max(ans, leftProfit[i] + rightProfit[i + 1]);
        }
        
        return ans;
    }
};