class Graph {
    vector<vector<pair<int,int>>> ajList;
    int totalNode;
public:
    Graph(int n, vector<vector<int>>& edges) {
        vector<pair<int,int>> weightedEdges;
        int i, u, v, cost;
        totalNode = n;

        for (i = 0; i < n; ++i) {
            ajList.push_back(weightedEdges);
        }

        for (i = 0; i < edges.size(); ++i) {
            u = edges[i][0];
            v = edges[i][1];
            cost = edges[i][2];

            ajList[u].push_back(make_pair(v, cost));
        }
    }
    
    void addEdge(vector<int> edge) {
        int u = edge[0], v = edge[1], cost = edge[2];
        ajList[u].push_back(make_pair(v, cost));
    }
    
    int shortestPath(int node1, int node2) {
        
        vector<int> distance(totalNode, INT_MAX);
        int i, u, v, cost;

        distance[node1] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        pq.push(make_pair(0, node1));

        while(!pq.empty()) {
            pair<int,int> edge = pq.top();
            pq.pop();

            cost = edge.first;
            u = edge.second;

            for (i = 0; i < ajList[u].size(); ++i) {
                v = ajList[u][i].first;
                cost = ajList[u][i].second;

                if (distance[v] > distance[u] + cost) {
                    distance[v] = distance[u] + cost;

                    pq.push(make_pair(distance[v], v));
                }
            }
        }

        return distance[node2] == INT_MAX ? -1 : distance[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */