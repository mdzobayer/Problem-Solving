class Solution {
    int n;
    vector<int> hold, free;
public:
    int maxProfit(vector<int>& prices, int fee) {
        n = prices.size();

        // Initally no previous profit so free is zero
        free.push_back(0);
        // We are holding first value
        hold.push_back(-prices.front());

        // Can my and hold on stock at a time. So it has only 2 state
        for (int i = 1; i < n; ++i) {
            // selling a stock. State goes to free
            int fr = hold.back() + prices[i] - fee;
            // Buying a stock. State goes to hold
            int ho = free.back() - prices[i];

            // If previsou is greater then or equal. Then consider previous
            // free and sell value, otherwise current free and sell value
            free.push_back(max(free.back(), fr));
            hold.push_back(max(hold.back(), ho));
        }

        // If you buy a stock then, you have to sell your stock. 
        // So last free is holding maximum profit amount.
        return free.back();
    }

    
};