class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int i, j, time = 0, n = tickets.size();

        while(tickets[k] > 0) {
            for (i = 0; i < n; ++i) {
                if (tickets[i] > 0) {
                    ++ time;
                    -- tickets[i];
                }

                if (tickets[k] == 0) break;
            }
        }
        
        return time;
    }
};