class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<bool> visited(n, false);
        vector<vector<int>> ajList(n, vector<int>());
        int i;

        for (i = 0; i < edges.size(); ++i) {
            ajList[edges[i][0]].push_back(edges[i][1]);
            ajList[edges[i][1]].push_back(edges[i][0]);
        }

        return bfs(ajList, visited, source, destination);
    }

    bool bfs(vector<vector<int>>& ajList, vector<bool>& visited, int source, int destination) {
        visited[source] = true;
        queue<int> q;
        q.push(source);

        while(!q.empty()) {
            source = q.front();
            q.pop();

            if (source == destination) return true;

            for (int nextNode : ajList[source]) {

                if (!visited[nextNode]) {
                    visited[nextNode] = true;
                    q.push(nextNode);
                }
            }
        }

        return false;
    }
};