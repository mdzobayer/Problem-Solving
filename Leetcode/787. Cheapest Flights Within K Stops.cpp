struct NewDestination {
    int node, kCount, cost;

    NewDestination(int n, int k, int c) {
        node = n;
        kCount = k;
        cost = c;
    }
};

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> ajlist(n);
        vector<int> costs(101, 1e9);
        int i;

        for (i = 0; i < flights.size(); ++i) {
            ajlist[flights[i][0]].push_back(make_pair(flights[i][1], flights[i][2]));
        }

        costs[src] = 0;
        NewDestination cDes(src, 0, 0);

        queue<NewDestination> q;
        q.push(cDes);

        while(!q.empty()) {
            cDes = q.front();
            q.pop();

            for (i = 0; i < ajlist[cDes.node].size() && cDes.kCount <= k; ++i) {
                NewDestination newDes(ajlist[cDes.node][i].first, cDes.kCount + 1, cDes.cost + ajlist[cDes.node][i].second);

                if (newDes.cost < costs[newDes.node]) {
                    costs[newDes.node] = newDes.cost;
                    q.push(newDes);
                }
            }
        }

        return costs[dst] != 1e9 ? costs[dst] : -1;
    }
};