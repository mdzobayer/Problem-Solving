class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        
        priority_queue<pair<int, int>> profitCost;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > capitalProfit;

        int i, maximizedCaptial = 0, profit, wealth = w;
        pair<int, int> aPair;
        for (i = 0; i < profits.size(); ++i) {
            capitalProfit.push(make_pair(capital[i], profits[i]));
        }

        while(k > 0) {
            while(!capitalProfit.empty() && capitalProfit.top().first <= wealth) {
                aPair = capitalProfit.top();
                capitalProfit.pop();

                profitCost.push(make_pair(aPair.second, aPair.first));
            }

            if (profitCost.empty()) break;

            aPair = profitCost.top();
            profitCost.pop();

            profit = aPair.first;
            maximizedCaptial += profit;
            wealth += profit;
            --k;
        }

        return maximizedCaptial + w;
    }
};