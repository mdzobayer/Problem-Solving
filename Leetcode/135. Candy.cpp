class Solution {
public:
    int candy(vector<int>& ratings) {
        int i, n = ratings.size();

        vector<int> candies(n, 1);

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        for (i = 0; i < n; ++i) {
            pq.push(make_pair(ratings[i], i));
        }
        pair<int, int> pairItem;
        int neighborMax = 1;
        while(!pq.empty()) {
            pairItem = pq.top();
            pq.pop();
            neighborMax = 1;

            // check left neighbor
            if (pairItem.second > 0) {
                if (ratings[pairItem.second] > ratings[pairItem.second - 1] && 
                candies[pairItem.second] <= candies[pairItem.second - 1]) {
                    candies[pairItem.second] = candies[pairItem.second - 1] + 1;
                }
            }

            // check right neighbor
            if (pairItem.second < n - 1) {
                if (ratings[pairItem.second] > ratings[pairItem.second + 1] && 
                candies[pairItem.second] <= candies[pairItem.second + 1]) {
                    candies[pairItem.second] = candies[pairItem.second + 1] + 1;
                }
            }
        }

        int ans = 0;
        for (i = 0; i < n; ++i) {
            ans += candies[i];
        }

        return ans;
    }
};