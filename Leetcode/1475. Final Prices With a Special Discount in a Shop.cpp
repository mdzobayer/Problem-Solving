class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int i, j, n = prices.size();
        vector<int> ans(n);

        for (i = 0; i < n; ++i) {
            ans[i] = prices[i];
            for (j = i + 1; j < n; ++j) {
                if (prices[j] <= prices[i]) {
                    ans[i] -= prices[j];
                    break;
                }
            }
        }

        return ans;
    }
};