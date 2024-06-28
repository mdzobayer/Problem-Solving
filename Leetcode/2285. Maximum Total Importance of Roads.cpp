class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector < vector<int> > ajlist(n);
        vector<int> assignedValue(n);
        long long i, u, v, ans = 0, current = n;

        for (i = 0; i < roads.size(); ++i) {
            u = roads[i][0];
            v = roads[i][1];

            ajlist[u].push_back(v);
            ajlist[v].push_back(u);
        }

        vector< pair<int,int> > sortedNodes;

        for (i = 0; i < n; ++i) {
            sortedNodes.push_back({ajlist[i].size(), i});
        }

        sort(sortedNodes.begin(), sortedNodes.end(), greater<pair<int,int>>());

        for (i = 0; i < n; ++i) {
            u = sortedNodes[i].second;
            assignedValue[u] = current;
            -- current;
        }

        for (i = 0; i < roads.size(); ++i) {
            u = roads[i][0];
            v = roads[i][1];

            ans += (assignedValue[u] + assignedValue[v]);
        }

        return ans;
    }
};