// Similar : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/?envType=list&envId=lspbbh5
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> frees, holds;
        int i, free, hold;

        frees.push_back(0);
        holds.push_back(-prices.front());

        for (i = 1; i < prices.size(); ++i) {
            free = holds.back() + prices[i];
            hold = frees.back() - prices[i];

            frees.push_back(max(free, frees.back()));
            holds.push_back(max(hold, holds.back()));
        }
        
        return frees.back();
    }
};