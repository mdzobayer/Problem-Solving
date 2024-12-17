class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> counts(26, 0);
        int i = 25;
        string ans = "";

        for (char ch : s) {
            ++ counts[ch - 'a'];
        }

        priority_queue<pair<int,int>> pq;
        while(i >= 0) {
            if (counts[i] > 0) {
                pq.push({i, counts[i]});
            }
            --i;
        }

        while(!pq.empty()) {
            int items = pq.top().second;
            int charac = pq.top().first;
            pq.pop();

            for (i = 0; i < min(repeatLimit, items); ++i) {
                ans += (char) charac + 'a';
            }

            if (items > repeatLimit) {
                items -= repeatLimit;
                if (pq.empty()) break;

                int nextItems = pq.top().second;
                int nextCharac = pq.top().first;
                pq.pop();

                ans += (char) nextCharac + 'a';
                -- nextItems;

                pq.push({charac, items});
                if(nextItems > 0) {
                    pq.push({nextCharac, nextItems});
                }
                
            }
        }

        return ans;
    }
};