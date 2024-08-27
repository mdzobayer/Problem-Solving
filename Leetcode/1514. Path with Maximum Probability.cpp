class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<double> maxProb(n);

        maxProb[start_node] = 1.0;

        for (int i = 0; i < n - 1; ++i) {
            bool hasUpdate = false;

            for (int j = 0; j < edges.size(); ++j) {
                double pathProb = succProb[j];
                int u = edges[j][0];
                int v = edges[j][1];

                if (maxProb[u] * pathProb > maxProb[v]) {
                    maxProb[v] = maxProb[u] * pathProb;
                    hasUpdate = true;
                }

                if (maxProb[v] * pathProb > maxProb[u]) {
                    maxProb[u] = maxProb[v] * pathProb;
                    hasUpdate = true;
                }
            }

            if (!hasUpdate) break;
        }

        return maxProb[end_node];
    }
};