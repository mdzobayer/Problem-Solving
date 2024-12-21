class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {

        if (n < 2) return 1;

        int ans = 0;
        vector< vector<int> > graph(n);
        vector<int> inDegree(n, 0);

        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
            ++inDegree[v];
            ++inDegree[u];
        }

        vector<long long> longValues(values.begin(), values.end());

        queue<int> queue;
        for (int node = 0; node < n; ++node) {
            if (inDegree[node] == 1) {
                queue.push(node);
            }
        }

        while(!queue.empty()) {
            int currentNode = queue.front();
            queue.pop();

            --inDegree[currentNode];

            long long addValue = 0;

            if (longValues[currentNode] % k == 0) {
                ++ ans;
            }
            else {
                addValue = longValues[currentNode];
            }

            for (int neighbor : graph[currentNode]) {
                if (inDegree[neighbor] == 0) {
                    continue;
                }

                inDegree[neighbor]--;
                longValues[neighbor] += addValue;

                if (inDegree[neighbor] == 1) {
                    queue.push(neighbor);
                }
            }
        }
        
        return ans;
    }
};