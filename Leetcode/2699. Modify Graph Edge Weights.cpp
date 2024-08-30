class Solution {
    int source, destination, n;
    const int INF = 2e9;
public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        this->n = n;
        this->source = source;
        this->destination = destination;

        long long currentShortDistance = runDijkstra(edges);

        if (currentShortDistance < target) return vector<vector<int>> {};

        bool matchesTarget = currentShortDistance == target;

        for (vector<int>&edge : edges) {
            if (edge[2] > 0) continue;

            edge[2] = matchesTarget ? INF : 1;

            if (!matchesTarget) {
                long long newDistance = runDijkstra(edges);
                if (newDistance <= target) {
                    matchesTarget = true;
                    edge[2] += target - newDistance;
                }
            }
        }

        return matchesTarget ? edges : vector<vector<int>> {};
    }

    long long runDijkstra(const vector<vector<int>>& edges) {
        vector< vector<long long> > adjMatrix(n, vector<long long>(n, INF));

        vector<long long> minDistance(n, INF);
        vector<bool> visited(n, false);

        minDistance[source] = 0;

        for (const vector<int>&edge : edges) {
            if (edge[2] != -1) {
                adjMatrix[edge[0]][edge[1]] = edge[2];
                adjMatrix[edge[1]][edge[0]] = edge[2];
            }
        }

        for (int i = 0; i < n; ++i) {
            int nearestUnvisitedNode = -1;

            for (int j = 0; j < n; ++j) {
                if (!visited[j] && (nearestUnvisitedNode == -1 || minDistance[j] < minDistance[nearestUnvisitedNode])) {
                    nearestUnvisitedNode = j;
                }
            }
            visited[nearestUnvisitedNode] = true;

            for (int v = 0; v < n; ++v) {
                minDistance[v] = min(minDistance[v], minDistance[nearestUnvisitedNode] + adjMatrix[nearestUnvisitedNode][v]);
            }
        }

        return minDistance[destination];
    }
};