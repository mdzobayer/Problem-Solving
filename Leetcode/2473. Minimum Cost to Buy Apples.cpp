class Solution {
public:
    vector<long long> minCost(int n, vector<vector<int>>& roads, vector<int>& appleCost, int k) {
        vector< vector< pair<int,int> > > graph (n, vector< pair<int,int> >());

        for (auto road : roads) {
            int a = road[0] - 1, b = road[1] - 1, cost = road[2];
            graph[a].push_back({b, cost});
            graph[b].push_back({a, cost});
        }

        vector<long long> ans (n);
        for(int i = 0; i < n; ++i) {
            ans[i] = solve(i, graph, appleCost, n, k);
        }

        return ans;
    }

    long long solve(int start, vector< vector< pair<int,int> > >& graph, vector<int>& appleCost, int n, int k) {
        
        vector<int> travelCosts(n, INT_MAX);
        travelCosts[start] = 0;

        priority_queue< vector<int>, vector< vector<int> >, greater<vector<int>> > minHeap;

        minHeap.push({0, start});
        long long minCost = INT_MAX;

        while(!minHeap.empty()) {
            auto current = minHeap.top();
            minHeap.pop();

            int travelCost = current[0];
            int currCity = current[1];

            minCost = min(minCost, static_cast<long long>(appleCost[currCity]) + (k + 1) * travelCost);

            for (auto &[neighbor, cost] : graph[currCity]) {
                int nextCost = travelCost + cost;
                if (nextCost < travelCosts[neighbor]) {
                    travelCosts[neighbor] = nextCost;
                    minHeap.push({nextCost, neighbor});
                }
            }
        }

        return minCost;
    }
};