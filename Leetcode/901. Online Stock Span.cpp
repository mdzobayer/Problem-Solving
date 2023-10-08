// Monotonic decreasing stack
class StockSpanner {
    vector<int> prices;
    stack<pair<int, int>> stk;
    int dayCount, lowestIndex, lowestValue;
public:
    StockSpanner() {
        dayCount = -1;
        lowestIndex = 0;
    }
    
    int next(int price) {
        ++dayCount;
        prices.push_back(price);

        int ans = 1;
        pair<int, int> pairItem;
        bool isRemovedAnyItem = false;

        while(!stk.empty()) {
            pairItem = stk.top();
            if (pairItem.first <= price) {
                stk.pop();
            }
            else break;
        }

        if (stk.size() == 0) {
            lowestIndex = dayCount;
            lowestValue = price;
            ans = dayCount + 1;
        }
        else {
            pairItem = stk.top();
            ans = dayCount - pairItem.second;
        }

        stk.push(make_pair(price, dayCount));

        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */