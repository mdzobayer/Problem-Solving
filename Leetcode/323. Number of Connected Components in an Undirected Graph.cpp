class Solution {
    ;
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int i, j, ans = 0;
        vector< vector<int> > ajList(n + 1, vector<int>());
        vector<bool> visited(n + 1, false);

        for (i = 0; i < edges.size(); ++i) {
            ajList[edges[i][0]].push_back(edges[i][1]);
            ajList[edges[i][1]].push_back(edges[i][0]);
        }

        for (i = 0; i < n; ++i) {
            if (!visited[i]) {
                ++ ans;
                bfs(i, visited, ajList);
            }
        }

        return ans;
    }

    void bfs(int root, vector<bool>& visited, vector< vector<int> >& ajList) {
        visited[root] = true;

        queue<int> q;
        q.push(root);

        while(!q.empty()) {
            root = q.front();
            q.pop();

            for (int i = 0; i < ajList[root].size(); ++i) {
                int next = ajList[root][i];
                if (!visited[next]) {
                    visited[next] = true;
                    q.push(next);
                }
            }
        }
    }
};