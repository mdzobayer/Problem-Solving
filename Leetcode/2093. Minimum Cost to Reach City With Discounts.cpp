class Solution {
    vector< vector< pair<int,int> > > ajlist;
public:
    int minimumCost(int n, vector<vector<int>>& highways, int discounts) {
        ajlist.resize(n + 1, vector< pair<int,int> >() );
        vector< vector< long long > > cost(n, vector< long long >(discounts + 1, INT_MAX) );
        

        for (auto highway : highways) {
            ajlist[highway[0]].push_back(make_pair(highway[1], highway[2]));
            ajlist[highway[1]].push_back(make_pair(highway[0], highway[2]));
        }

        dijkstraAlgorithm(0, n - 1, discounts, cost);

        int ans = cost[n - 1][0];
        for (int data : cost[n - 1]) {
            ans = min(ans, data);
        }

        if (ans == INT_MAX) ans = -1;

        return ans;
    }

    void dijkstraAlgorithm(int source, int destination, int discounts, vector< vector< long long > > & cost) {

        queue< pair<int, int> > q;
        q.push(make_pair(source, discounts));
        cost[source][discounts] = 0;

        while(!q.empty()) {
            int current = q.front().first;
            int availableDiscounts = q.front().second;
            q.pop();

            for (int i = 0; i < ajlist[current].size(); ++i) {
                int nextNode = ajlist[current][i].first;
                int nextNodeCost = ajlist[current][i].second;

                if (cost[nextNode][availableDiscounts] > cost[current][availableDiscounts] + nextNodeCost) {
                    cost[nextNode][availableDiscounts] = cost[current][availableDiscounts] + nextNodeCost;
                    q.push(make_pair(nextNode, availableDiscounts));
                }

                if (availableDiscounts > 0 && cost[nextNode][availableDiscounts - 1] > cost[current][availableDiscounts] + (nextNodeCost / 2)) {
                    cost[nextNode][availableDiscounts - 1] = cost[current][availableDiscounts] + (nextNodeCost / 2);
                    q.push(make_pair(nextNode, availableDiscounts - 1));
                }
            }
        }
    }
};