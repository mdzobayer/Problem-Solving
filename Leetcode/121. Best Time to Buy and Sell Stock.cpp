
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i, maxPossible = 0, n = prices.size();
        vector<int> maxSoFar(n);

        maxSoFar[n - 1] = prices.back();
        for (i = n - 2; i >= 0; --i) {
            if (prices[i] < maxSoFar[i+1]) {
                maxSoFar[i] = maxSoFar[i+1];
            }
            else {
                maxSoFar[i] = prices[i];
            }
        }
        
        for (i = 0; i < n - 1; ++i) {
            maxPossible = max(maxPossible, maxSoFar[i + 1] - prices[i]);
        }
        
        return maxPossible;
    }
};